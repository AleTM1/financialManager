//
// Created by alessandro on 13/08/18.
//

#include "Conto.h"
#include <ctime>
#include <cstdlib>


Conto::Conto() {
    group="Conto";
}

void Conto::contoGenerator() {

    saldo=20000;
    liquid=saldo;
    invested=0;

    IBAN = IBANgenerator();

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
            iban.append(n);

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
}

int Conto::getInvested() const {
    return invested;
}

void Conto::setInvested(int invested) {
    Conto::invested = invested;
}


//------------------------------------------------------

void Conto::loadData() {

    data.beginGroup("Conto");




    data.endGroup();

    data.sync();
}


void Conto::saveData(std::vector<QString> strings) {



    data.beginGroup("Conto");




    data.endGroup();

    data.sync();

}






