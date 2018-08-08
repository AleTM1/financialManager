//
// Created by alessandro on 08/08/18.
//

#include "Account.h"

const QString &Account::getName() const {
    return name;
}

void Account::setName(const QString &name) {
    Account::name = name;
}

const QString &Account::getSurname() const {
    return surname;
}

void Account::setSurname(const QString &surname) {
    Account::surname = surname;
}

const QString &Account::getCity() const {
    return city;
}

void Account::setCity(const QString &city) {
    Account::city = city;
}

const QString &Account::getCAP() const {
    return CAP;
}

void Account::setCAP(const QString &CAP) {
    Account::CAP = CAP;
}

const QString &Account::getAddress() const {
    return address;
}

void Account::setAddress(const QString &address) {
    Account::address = address;
}

const QString &Account::getPhoneNumber() const {
    return phoneNumber;
}

void Account::setPhoneNumber(const QString &phoneNumber) {
    Account::phoneNumber = phoneNumber;
}

const QString &Account::getMail() const {
    return mail;
}

void Account::setMail(const QString &mail) {
    Account::mail = mail;
}

