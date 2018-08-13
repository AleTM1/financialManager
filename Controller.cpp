//
// Created by alessandro on 07/08/18.
//

#include "Controller.h"

void Controller::openingApp() {

    if(model->firstOpening()){

        model->setTabAccountLocked(true);

    }else{

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

void Controller::ContoSave(std::map<std::string, QString> strings) {

    model->save("conto", strings);

}



//---------------------------