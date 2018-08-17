//
// Created by alessandro on 13/08/18.
//

#include "Conto.h"
#include <ctime>
#include <cstdlib>


Conto::Conto():group("Conto") {}

void Conto::contoGenerator() {

    title="Conto corrente";
    saldo=20000;
    liquid=saldo;
    invested=0;

    IBAN = IBANgenerator();

    std::map<std::string, QString> string;
    string.insert(std::make_pair("title",title));
    saveData(string);

}

QString Conto::IBANgenerator() {

    srand(time(0));
    QString iban="IT";
    int n;

    for(int i=0; i<25 ;i++) {
        if (i==2){

            iban.append("Y");

        }else{

            n=rand()%10;
            iban.append(QString::number(n));

        }

    }

    return iban;

}

//------------------------GETTER AND SETTER-----------------

const QString &Conto::getIBAN() const {
    return IBAN;
}

int Conto::getSaldo() const {
    return saldo;
}

void Conto::setSaldo(int saldo) {
    Conto::saldo = saldo;
}

int Conto::getLiquid() const {
    return liquid;
}

void Conto::setLiquid(int liquid) {
    Conto::liquid = liquid;
    saldo = liquid + invested;
}

int Conto::getInvested() const {
    return invested;
}

void Conto::setInvested(int invested) {
    Conto::invested = invested;
    saldo = liquid + invested;
}

const QString &Conto::getTitle() const {
    return title;
}

void Conto::setTitle(const QString &title) {
    Conto::title = title;
}


//------------------------------------------------------

void Conto::loadData() {

    data.beginGroup("Conto");

    title=data.value("title","").toString();
    IBAN=data.value("IBAN","").toString();
    saldo=data.value("saldo","").toInt();
    liquid=data.value("liquid","").toInt();
    invested=data.value("invested","").toInt();

    data.endGroup();

    data.sync();
}


void Conto::saveData(std::map<std::string, QString> string) {

    title=string["title"];

    data.beginGroup("Conto");

    data.setValue("title", title);
    data.setValue("IBAN", IBAN);
    data.setValue("saldo", saldo);
    data.setValue("liquid", liquid);
    data.setValue("invested", invested);

    data.endGroup();

    data.sync();

}






