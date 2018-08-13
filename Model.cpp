//
// Created by alessandro on 07/08/18.
//

#include "Model.h"

Model::Model():account(new Account){

    dataStorages.push_back(account);

}

Model::~Model(){

    delete account;

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

Account* Model::accessAccount() const {
    return account;
}

//----------------------------------------


bool Model::firstOpening() {

    return account->isFirstOpening();

}



void Model::loadAll() {


    for (auto dataClass : dataStorages)
        dataClass->loadData();

    notify();

}

void Model::loadAccount() {

    account->loadData();

}

void Model::loadConto() {



}

void Model::clearAll() {

    for (auto dataClass : dataStorages)
        dataClass->clear();

    notify();
    setTabAccountLocked(true);
    notify();
}

void Model::save(std::string classType, std::vector<QString> strings) {


    if(classType=="account"){
        account->saveData(strings);
    }


}

