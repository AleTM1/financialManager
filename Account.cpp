//
// Created by alessandro on 08/08/18.
//

#include "Account.h"

const QString &Account::getName() const {
    return name;
}

const QString &Account::getSurname() const {
    return surname;
}


const QString &Account::getCity() const {
    return city;
}

const QString &Account::getCAP() const {
    return CAP;
}

const QString &Account::getAddress() const {
    return address;
}

const QString &Account::getPhoneNumber() const {
    return phoneNumber;
}

const QString &Account::getMail() const {
    return mail;
}

//-----------------------------------------------------------------


bool Account::isFirstOpening() {

    bool result = !(data.contains("Account/name"));
    return result;

}

void Account::loadData() {

    data.beginGroup("Account");
    name=data.value("name","").toString();
    surname=data.value("surname","").toString();
    city=data.value("city","").toString();
    CAP=data.value("CAP","").toString();
    address=data.value("address","").toString();
    phoneNumber=data.value("phoneNumber","").toString();
    mail=data.value("mail","").toString();
    data.endGroup();

    data.sync();
}


void Account::saveData(std::map<std::string, QString> strings) {

    name=strings["name"];
    surname=strings["surname"];
    city=strings["city"];
    CAP=strings["CAP"];
    address=strings["address"];
    phoneNumber=strings["phoneNumber"];
    mail=strings["mail"];


    data.beginGroup("Account");

    data.setValue("name", name);
    data.setValue("surname", surname);
    data.setValue("city", city);
    data.setValue("CAP", CAP);
    data.setValue("address", address);
    data.setValue("phoneNumber", phoneNumber);
    data.setValue("mail", mail);

    data.endGroup();



    data.sync();

}

