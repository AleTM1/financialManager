//
// Created by alessandro on 25/08/18.
//

#ifndef FINANCIALMANAGER_ABSTRACTSTOCKFUND_H
#define FINANCIALMANAGER_ABSTRACTSTOCKFUND_H


#include "Investment.h"

class Stock : public Investment {

public:

    Stock();

    virtual void totalInvestmentCalculator();

    virtual ~Stock(){}

    float getSharesNumber() const;

    void setSharesNumber(float sharesNumber);

    float getActualInvestment() const;

    void setActualInvestment(float actualInvestment);

    virtual void setEntity(Company *entity) override;

    virtual void showEntityDetails() override;


protected:

    float sharesNumber;
    float actualInvestment;

};


#endif //FINANCIALMANAGER_ABSTRACTSTOCKFUND_H
