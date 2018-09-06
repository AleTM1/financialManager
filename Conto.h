//
// Created by alessandro on 13/08/18.
//

#ifndef FINANCIALMANAGER_CONTO_H
#define FINANCIALMANAGER_CONTO_H

#include "AbstractDataStorage.h"
#include "Transaction.h"
#include "enumSaving.h"

class Conto : public AbstractDataStorage {

public:  //methods

	Conto ();

	void contoGenerator ();

	virtual void loadData () override;

	virtual void changeData ( QString );

	virtual void saveData () override;

public:  //getter and setter

	const QString &getIBAN () const;

	float getSaldo () const;

	void setSaldo ( float saldo );

	float getLiquid () const;

	void setLiquid ( float liquid );

	float getInvested () const;

	void setInvested ( float invested );

	const QString &getTitle () const;

	void setTitle ( const QString &title );

protected: //data

	QString title;

	QString IBAN;

	float saldo;

	float liquid;

	float invested;

private: //privates methods

	QString IBANgenerator ();

};

#endif //FINANCIALMANAGER_CONTO_H
