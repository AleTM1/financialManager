//
// Created by alessandro on 08/08/18.
//

#include "Account.h"

const QString& Account::getName() const {

    return name;
}

const QString& Account::getSurname() const {

    return surname;
}

const QString& Account::getCodiceFiscale() const {

    return codiceFiscale;
}

const QString& Account::getCity() const {

    return city;
}

const QString& Account::getCAP() const {

    return CAP;
}

const QString& Account::getAddress() const {

    return address;
}

const QString& Account::getPhoneNumber() const {

    return phoneNumber;
}

const QString& Account::getMail() const {

    return mail;
}

//-----------------------------------------------------------------


bool Account::isFirstOpening() {

    bool result = !(data.contains("Account/"+QString::number(AccountData::name)));
    return result;

}

void Account::loadData() {

    data.beginGroup(groupName);

    name = data.value(QString::number(AccountData::name), "").toString();
    surname = data.value(QString::number(AccountData::surname), "").toString();
    codiceFiscale = data.value(QString::number(AccountData::codiceFiscale), "").toString();
    city = data.value(QString::number(AccountData::city), "").toString();
    CAP = data.value(QString::number(AccountData::CAP), "").toString();
    address = data.value(QString::number(AccountData::address), "").toString();
    phoneNumber = data.value(QString::number(AccountData::phoneNumber), "").toString();
    mail = data.value(QString::number(AccountData::mail), "").toString();

    data.endGroup();

    data.sync();
}

void Account::changeData(std::map<AccountData, QString> strings) {

    name = strings[AccountData::name];
    surname = strings[AccountData::surname];
    codiceFiscale = strings[AccountData::codiceFiscale];
    city = strings[AccountData::city];
    CAP = strings[AccountData::CAP];
    address = strings[AccountData::address];
    phoneNumber = strings[AccountData::phoneNumber];
    mail = strings[AccountData::mail];

    saveData();

}

void Account::saveData() {

    data.beginGroup(groupName);

    data.setValue(QString::number(AccountData::name), name);
    data.setValue(QString::number(AccountData::surname), surname);
    data.setValue(QString::number(AccountData::codiceFiscale), codiceFiscale);
    data.setValue(QString::number(AccountData::city), city);
    data.setValue(QString::number(AccountData::CAP), CAP);
    data.setValue(QString::number(AccountData::address), address);
    data.setValue(QString::number(AccountData::phoneNumber), phoneNumber);
    data.setValue(QString::number(AccountData::mail), mail);

    data.endGroup();

    data.sync();

}



