//
// Created by alessandro on 07/08/18.
//

#include "Model.h"

Model::Model():account(new Account){

}

Model::~Model(){

    delete account;

}

//----------------------------------------

bool Model::isTabAccountLocked() const {
    return tabAccountLocked;
}

void Model::setTabAccountLocked(bool tabAccountLocked) {
    Model::tabAccountLocked = tabAccountLocked;
}

const Account* Model::accessAccount() const {
    return account;
}

//----------------------------------------


bool Model::firstOpening() {

    return account->isFirstOpening();

}



void Model::loadAll() {

    loadAccount();

    //TODO per tutte le classi attributo
    //loadConto();

}

void Model::loadAccount() {

    account->loadData();

}

void Model::loadConto() {



}

void Model::clearAll() {

    account->clear();

    //TODO per tutte le classi attributo

}

