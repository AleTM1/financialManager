//
// Created by alessandro on 07/08/18.
//

#include "Model.h"

Model::Model():account(new Account), conto(new Conto), historical(new Historical){

    dataStorages.push_back(account);
    dataStorages.push_back(conto);
    dataStorages.push_back(historical);

}

Model::~Model(){

    delete account;
    delete conto;

    dataStorages.clear();

}

//----------------------------------------

bool Model::isTabAccountLocked() const {
    return tabAccountLocked;
}

void Model::setTabAccountLocked(bool tabAccountLocked) {
    Model::tabAccountLocked = tabAccountLocked;
    notify();
}

AbstractDataStorage *Model::accessDataStorage(std::string groupName) const {

    for (auto dataClass : dataStorages)
        if(groupName == dataClass->getGroup().toStdString())
            return dataClass;


}

ErrorLog *Model::getErrorLog() const {
    return errorLog;
}


//----------------------------------------


bool Model::isFirstOpening() {

    return account->isFirstOpening();

}

void Model::createAccount() {

    conto->contoGenerator();
    notify();

}


void Model::loadAll() {


    for (auto dataClass : dataStorages)
        dataClass->loadData();

    notify();

}

void Model::clearAll() {

    for (auto dataClass : dataStorages)
        dataClass->clear();

    notify();
    setTabAccountLocked(true);
    notify();
}

//---------------------------------Salvataggi

int Model::saveAccount(std::map<std::string, QString> strings) {

    /*  0) buon fine
     *  1) nome non valido
     *  2) cognome non valido
     *  3) Codice Fiscale non valido
     *  4) città non valido
     *  5) CAP non valido
     *  6) indirizzo non valido
     *  7) telefono non valido
     *  8) mail non valido
     */
    if(strings["name"].length()<2)
        return 1;

    if(strings["surname"].length()<2)
        return 2;

    if(strings["codiceFiscale"].length() != 16)
        return 3;

    if(strings["city"].length()<2)
        return 4;

    if(strings["CAP"].length() != 5)
        return 5;

    if(strings["address"].length()<2)
        return 6;

    if(strings["phoneNumber"].length() != 10)
        return 7;

    if(strings["mail"].length() < 6 || strings["mail"].count('@')!=1 || !strings["mail"].contains('.'))
        return 8;

    account->changeData(strings);

    notify();

    return 0;


}

void Model::saveConto(QString string) {

    conto->changeData(string);

    notify();

}

void Model::saveHistorical(Transaction transaction) {

    historical->addTransaction(transaction);

    notify();

}

//----------------------------------------------

int Model::doTransaction(Transaction transaction) {

    /*  0) buon fine
     *  1) nome dell'ordinante non valido
     *  2) IBAN dell'ordinante non valido
     *  3) nome del beneficiario non valido
     *  4) IBAN del beneficiario non valido
     *  5) importo non valido
     *  6) importo eccessivo
     *  7) causale mancante
     */
    if(transaction.getPayerName().trimmed().length() < 4 || !transaction.getPayerName().contains(" ") )
        return 1;

    if(transaction.getPayerIBAN().length() != 27)
        return 2;

    if(transaction.getReceiverName().trimmed().length() < 4 || !transaction.getReceiverName().contains(" ") )
        return 3;

    if(transaction.getReceiverIBAN().trimmed().length() != 27)
        return 4;

    if(transaction.getAmount() == 0)
        return 5;

    if(transaction.isDebit() && transaction.getAmount() > conto->getLiquid())
        return 6;

    if(transaction.getCausal().trimmed().length() < 3)
        return 7;


    if(transaction.isDebit())
        conto->setLiquid( conto->getLiquid() - transaction.getAmount() );
    else
        conto->setLiquid( conto->getLiquid() + transaction.getAmount() );

    conto->saveData();

    historical->addTransaction(transaction);

    notify();

    return 0;

}

void Model::makeMessageDialogNoButtons(QString ttl, QString txt) {

    if(errorLog!=nullptr)
        delete errorLog;

    errorLog = new ErrorLog(ttl, txt);

    notify();

}

void Model::changeHistoricalOrder(OrderTime o){

    historical->setOrder(o);

    notify();

}



