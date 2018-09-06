//
// Created by alessandro on 13/08/18.
//

#include "Conto.h"
#include <ctime>
#include <cstdlib>

Conto::Conto () { groupName = "Conto"; }

void Conto::contoGenerator () {

	title = "Conto corrente";
	saldo = 20000;
	liquid = saldo;
	invested = 0;

	IBAN = IBANgenerator();

	changeData(title);

}

QString Conto::IBANgenerator () {

	srand(time(0));
	QString iban = "IT";
	int n;

	for ( int i = 0; i < 25; i++ ) {
		if ( i == 2 ) {

			iban.append("Y");

		} else {

			n = rand() % 10;
			iban.append(QString::number(n));

		}

	}

	return iban;

}

//------------------------GETTER AND SETTER-----------------

const QString &Conto::getIBAN () const {

	return IBAN;
}

float Conto::getSaldo () const {

	return saldo;
}

void Conto::setSaldo ( float saldo ) {

	Conto::saldo = saldo;
}

float Conto::getLiquid () const {

	return liquid;
}

void Conto::setLiquid ( float liquid ) {

	Conto::liquid = liquid;
	saldo = liquid + invested;
}

float Conto::getInvested () const {

	return invested;
}

void Conto::setInvested ( float invested ) {

	Conto::invested = invested;
	saldo = liquid + invested;
}

const QString &Conto::getTitle () const {

	return title;
}

void Conto::setTitle ( const QString &title ) {

	Conto::title = title;
}


//------------------------------------------------------

void Conto::loadData () {

	data.beginGroup(groupName);

	title = data.value(QString::number(ContoData::title), "").toString();
	IBAN = data.value(QString::number(ContoData::IBAN), "").toString();
	saldo = data.value(QString::number(ContoData::saldo), "").toFloat();
	liquid = data.value(QString::number(ContoData::liquid), "").toFloat();
	invested = data.value(QString::number(ContoData::invested), "").toFloat();

	data.endGroup();

	data.sync();
}

void Conto::changeData ( QString string ) {

	title = string;

	saveData();
}

void Conto::saveData () {

	data.beginGroup(groupName);

	data.setValue(QString::number(ContoData::title), title);
	data.setValue(QString::number(ContoData::IBAN), IBAN);
	data.setValue(QString::number(ContoData::saldo), saldo);
	data.setValue(QString::number(ContoData::liquid), liquid);
	data.setValue(QString::number(ContoData::invested), invested);

	data.endGroup();

	data.sync();

}






