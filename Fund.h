//
// Created by alessandro on 25/08/18.
//

#ifndef FINANCIALMANAGER_FUND_H
#define FINANCIALMANAGER_FUND_H


#include "AbstractStockFund.h"
#include "FundSociety.h"


class Fund : public AbstractStockFund{

public:

    Fund(float sharesNum);

    virtual void totalInvestmentCalculator() override ;

    virtual void showEntityDetails() override;

    float getCostAmount() const;

protected:

    float costAmount;

};


#endif //FINANCIALMANAGER_FUND_H
