//
// Created by alessandro on 25/08/18.
//

#ifndef FINANCIALMANAGER_FUND_H
#define FINANCIALMANAGER_FUND_H


#include "AbstractStockFund.h"

class Fund : AbstractStockFund{

public:

    Fund(float sharesNum);

    virtual void showEntityDetails() override;

protected:



};


#endif //FINANCIALMANAGER_FUND_H
