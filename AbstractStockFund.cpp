//
// Created by alessandro on 25/08/18.
//

#include "AbstractStockFund.h"


void AbstractStockFund::totalInvestmentCalculator() {

    totalInvested = entity->getShareCost() * sharesNumber;

}

void AbstractStockFund::changeGenerator() {

    entity->setShareCost(entity->getShareCost() * (((rand()%200-100)/100.0)+100.0)/100.0 );

}



float AbstractStockFund::getSharesNumber() const {
    return sharesNumber;
}

void AbstractStockFund::setSharesNumber(float shareNumber) {
    AbstractStockFund::sharesNumber = shareNumber;
}
