//
// Created by alessandro on 07/08/18.
//

#include "Controller.h"

void Controller::openingApp() {

    if(model->isFirstOpening()){

        model->setTabAccountLocked(true);

        model->createAccount();

    }else{

        model->setTabAccountLocked(false);

        model->loadAll();

    }


}

void Controller::reset() {

    model->clearAll();

}


void Controller::doTransaction(bool d, std::map<std::string, QString> dataTransaction) {

    Transaction transaction(d, dataTransaction["payerName"], dataTransaction["payerIBAN"], dataTransaction["receiverName"], dataTransaction["receiverIBAN"], (dataTransaction["amount"]).toInt(), dataTransaction["causal"] );

    if(model->doTransaction(transaction)){

    }else{

    }

}


//--------------------------------- Salvataggi


void Controller::accountSave(std::map<std::string, QString> strings) {

    model->saveAccount(strings);
    model->setTabAccountLocked(false);

}

void Controller::contoSave(QString string) {

    model->saveConto(string);

}



//---------------------------