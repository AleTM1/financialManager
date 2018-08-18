//
// Created by alessandro on 07/08/18.
//

#include "Controller.h"

void Controller::openingApp() {

    if(model->isFirstOpening()){

        model->setTabAccountLocked(true);

    }else{

        model->setTabAccountLocked(false);

        model->loadAll();

    }


}

void Controller::reset() {

    model->clearAll();

}


void Controller::doTransaction(bool d, std::map<std::string, QString> dataTransaction, QDate date) {

    Transaction transaction(d, dataTransaction["payerName"], dataTransaction["payerIBAN"], dataTransaction["receiverName"], dataTransaction["receiverIBAN"], (dataTransaction["amount"]).toInt(), dataTransaction["causal"], date );

    switch(model->doTransaction(transaction)) {
        case 0: model->makeMessageDialogNoButtons("transazione riuscita", "Transazione effettuata con successo!");
            break;
        case 1: model->makeMessageDialogNoButtons("transazione fallita", "Nome dell'ordinante non valido");
            break;
        case 2: model->makeMessageDialogNoButtons("transazione fallita", "IBAN dell'ordinante non valido");
            break;
        case 3: model->makeMessageDialogNoButtons("transazione fallita", "Nome del beneficiario non valido");
            break;
        case 4: model->makeMessageDialogNoButtons("transazione fallita", "IBAN del beneficiario non valido");
            break;
        case 5: model->makeMessageDialogNoButtons("transazione fallita", "Importo non valido");
            break;
        case 6: model->makeMessageDialogNoButtons("transazione fallita", "La cifra che si sta tentando di inviare eccede la liquidità massima disponibile.");
            break;
        case 7: model->makeMessageDialogNoButtons("transazione fallita", "La causale deve essere composta da almento 3 caratteri");
            break;

        default: model->makeMessageDialogNoButtons("transazione fallita", "Errore sconosciuto");
    }


}


//--------------------------------- Salvataggi


void Controller::accountSave(std::map<std::string, QString> strings) {

    model->saveAccount(strings);

    if(model->isTabAccountLocked()) {
        model->setTabAccountLocked(false);
        model->createAccount();
    }

}

void Controller::contoSave(QString string) {

    model->saveConto(string);

}



//---------------------------