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

void Model::saveAccount(std::map<std::string, QString> strings) {

    account->changeData(strings);

    notify();

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

bool Model::doTransaction(Transaction transaction) {

    if(transaction.isDebit() && transaction.getAmount()>conto->getLiquid())
        return false;


    conto->setLiquid( conto->getLiquid() - transaction.getAmount() );
    conto->saveData();

    historical->addTransaction(transaction);

    notify();

    return true;

}



