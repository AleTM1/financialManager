//
// Created by alessandro on 13/08/18.
//

#ifndef FINANCIALMANAGER_CONTO_H
#define FINANCIALMANAGER_CONTO_H


#include "AbstractDataStorage.h"
#include "Transaction.h"

class Conto : public AbstractDataStorage{

public:  //methods

    Conto();

    void contoGenerator();

    virtual void loadData() override;

    virtual void changeData(QString);

    virtual void saveData() override;


public:  //getter and setter

    const QString &getIBAN() const;

    int getSaldo() const;

    void setSaldo(int saldo);

    int getLiquid() const;

    void setLiquid(int liquid);

    int getInvested() const;

    void setInvested(int invested);

    const QString &getTitle() const;

    void setTitle(const QString &title);

protected: //data

    QString title;
    QString IBAN;
    int saldo;
    int liquid;
    int invested;


private: //privates methods

    QString IBANgenerator();

};


#endif //FINANCIALMANAGER_CONTO_H
