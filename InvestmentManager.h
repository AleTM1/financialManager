//
// Created by alessandro on 26/08/18.
//

#ifndef FINANCIALMANAGER_INVESTMENTMANAGER_H
#define FINANCIALMANAGER_INVESTMENTMANAGER_H


#include "AbstractDataStorage.h"
#include "Investment.h"
#include "enumInvestmentType.h"

class InvestmentManager : public AbstractDataStorage{

public:

    InvestmentManager();

    ~InvestmentManager();

    void addInvestment(Investment*);

    virtual void saveData() override;

    virtual void loadData() override;

    const std::list<Investment *> &getInvestmentList() const;

private:



protected:


    std::list<Investment*> investmentList;


};


#endif //FINANCIALMANAGER_INVESTMENTMANAGER_H
