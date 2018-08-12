//
// Created by alessandro on 07/08/18.
//

#include "Controller.h"

void Controller::openingApp() {

    if(model->firstOpening()){

        model->setTabAccountLocked(true);
        model->notify();

    }else{

        model->loadAll();
        model->notify();

    }

}
