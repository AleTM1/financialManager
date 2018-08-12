//
// Created by alessandro on 07/08/18.
//

#include "Model.h"

Model::Model(){


}

Model::~Model(){


}

//----------------------------------------

bool Model::isTabAccountLocked() const {
    return tabAccountLocked;
}

void Model::setTabAccountLocked(bool tabAccountLocked) {
    Model::tabAccountLocked = tabAccountLocked;
}

const Account& Model::accessAccount() const {
    return account;
}

//----------------------------------------


bool Model::firstOpening() {

    return account.isFirstOpening();

}



void Model::loadAll() {

    loadAccount();

    //loadConto();

}

void Model::loadAccount() {

    account.loadAccount();

}

void Model::loadConto() {



}

