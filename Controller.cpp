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

    if(model->doTransaction(transaction)){

        model->makeMessageDialogNoButtons("transazione riuscita", "Transazione effettuata con successo!");

    }else{

        model->makeMessageDialogNoButtons("transazione fallita", "La cifra che si sta tentando di inviare eccede la liquidità massima disponibile.");

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