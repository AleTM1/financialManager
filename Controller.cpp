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

//---------------------------------
// Salvataggi


void Controller::accountSave(std::map<std::string, QString> strings) {

    model->save("account", strings);
    model->setTabAccountLocked(false);

}

void Controller::contoSave(std::map<std::string, QString> strings) {

    model->save("conto", strings);

}



//---------------------------