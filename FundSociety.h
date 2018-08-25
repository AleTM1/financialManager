//
// Created by alessandro on 25/08/18.
//

#ifndef FINANCIALMANAGER_FUNDSOCIETY_H
#define FINANCIALMANAGER_FUNDSOCIETY_H


#include "Entity.h"
#include "Investment.h"
#include <list>

class FundSociety : public Entity{

public:

    FundSociety(float c, QString nam, QString isin, float cost):cost(c), Entity(nam, isin, cost){}

    virtual ~FundSociety();

    void generateComposition();

    const std::list<Investment *> &getFundComposition() const;

    void setFundComposition(const std::list<Investment *> &fundComposition);

    float getCost() const;

    void setCost(float cost);

protected:

    std::list<Investment*> fundComposition;
    float cost;

};


#endif //FINANCIALMANAGER_FUNDSOCIETY_H
