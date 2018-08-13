//
// Created by alessandro on 13/08/18.
//

#ifndef FINANCIALMANAGER_CONTO_H
#define FINANCIALMANAGER_CONTO_H


#include "AbstractDataStorage.h"

class Conto : public AbstractDataStorage{

public:

    Conto();

    void contoGenerator();

    virtual void loadData() override;

    virtual void saveData(std::vector<QString>) override;


public:

    const QString &getIBAN() const;

    int getSaldo() const;

    void setSaldo(int saldo);

    int getLiquid() const;

    void setLiquid(int liquid);

    int getInvested() const;

    void setInvested(int invested);


protected:

    QString IBAN;
    int saldo;
    int liquid;
    int invested;

private:

    QString IBANgenerator();

};


#endif //FINANCIALMANAGER_CONTO_H
