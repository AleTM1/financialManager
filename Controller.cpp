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
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6: model->makeMessageDialogNoButtons("transazione fallita", "La cifra che si sta tentando di inviare eccede la liquidità massima disponibile.");
            break;

        default: model->makeMessageDialogNoButtons("transazione riuscita", "Transazione effettuata con successo!");
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