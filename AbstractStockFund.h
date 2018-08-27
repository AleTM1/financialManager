//
// Created by alessandro on 25/08/18.
//

#ifndef FINANCIALMANAGER_ABSTRACTSTOCKFUND_H
#define FINANCIALMANAGER_ABSTRACTSTOCKFUND_H


#include "Investment.h"

class AbstractStockFund : public Investment {

public:

    AbstractStockFund(float sharesNum);

    void totalInvestmentCalculator();

    virtual ~AbstractStockFund(){}

    float getSharesNumber() const;

    void setSharesNumber(float sharesNumber);

    float getActualInvestment() const;

    void setActualInvestment(float actualInvestment);

    void setEntity(Entity *entity);

protected:

    float sharesNumber;
    float actualInvestment;

};


#endif //FINANCIALMANAGER_ABSTRACTSTOCKFUND_H
