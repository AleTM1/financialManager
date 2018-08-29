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

    virtual void setCompany(Company *entity) override;

protected:

    float sharesNumber;

};


#endif //FINANCIALMANAGER_ABSTRACTSTOCKFUND_H
