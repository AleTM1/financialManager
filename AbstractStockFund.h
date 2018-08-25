//
// Created by alessandro on 25/08/18.
//

#ifndef FINANCIALMANAGER_ABSTRACTSTOCKFUND_H
#define FINANCIALMANAGER_ABSTRACTSTOCKFUND_H


#include "Investment.h"
#include "ctime"

class AbstractStockFund : public Investment {

public:


    void changeGenerator();

    void totalInvestmentCalculator();

    virtual ~AbstractStockFund(){}

    float getSharesNumber() const;

    void setSharesNumber(float sharesNumber);

protected:

    float sharesNumber;

};


#endif //FINANCIALMANAGER_ABSTRACTSTOCKFUND_H
