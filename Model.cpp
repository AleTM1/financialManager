//
// Created by alessandro on 07/08/18.
//

#include "Model.h"

Model::Model():account(new Account), conto(new Conto){

    dataStorages.push_back(account);
    dataStorages.push_back(conto);

}

Model::~Model(){

    delete account;
    delete conto;

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

AbstractDataStorage *Model::accessDataStorage(std::string groupName) const {

    for (auto dataClass : dataStorages)
        if(groupName == dataClass->getGroup().toStdString())
            return dataClass;


}


//----------------------------------------


bool Model::isFirstOpening() {

    return account->isFirstOpening();

}

void Model::createAccount() {

    conto->contoGenerator();
    notify();

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

    conto->loadData();

}

void Model::clearAll() {

    for (auto dataClass : dataStorages)
        dataClass->clear();

    notify();
    setTabAccountLocked(true);
    notify();
}

void Model::save(std::string classType, std::map<std::string, QString> strings) {


     for (auto dataClass : dataStorages)
        if(classType == dataClass->getGroup().toStdString())
            dataClass->saveData(strings);


    notify();

}



