//
// Created by alessandro on 25/08/18.
//

#ifndef FINANCIALMANAGER_STOCK_H
#define FINANCIALMANAGER_STOCK_H


#include "AbstractStockFund.h"

class Stock : public AbstractStockFund {

public:

    Stock();


    virtual void showEntityDetails() override;

protected:

};


#endif //FINANCIALMANAGER_STOCK_H
