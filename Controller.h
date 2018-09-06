//
// Created by alessandro on 07/08/18.
//

#ifndef QTPROVA_CONTROLLER_H
#define QTPROVA_CONTROLLER_H

#include "Model.h"

class Controller {

public:

    explicit Controller(Model* m) :model(m) { }

    void openingApp();

    void reset();

    void doTransaction(bool, std::map<TransactionData, QString>, QDate);

    void changeHistoricalOrder(bool, QString txt, QDate from, QDate to, QString option);

    void doInvestment(InvestmentType, QString ISINcode, float quantity);

    void doInvestment(InvestmentType, QString ISINcode, float investmentAmount, int monthsNumber);

    void sell(int);

    //---------------salvataggi

    void accountSave(std::map<AccountData, QString>);

    void contoSave(QString);

    //-----------------------

private:

    Model* model;

};

#endif //QTPROVA_CONTROLLER_H
