//
// Created by alessandro on 25/08/18.
//

#include "AbstractStockFund.h"


AbstractStockFund::AbstractStockFund(float sharesNum) : sharesNumber(sharesNum) {

    totalInvestmentCalculator();

    actualInvestment = totalInvested;

}

void AbstractStockFund::totalInvestmentCalculator() {

    totalInvested = entity->getShareCost() * sharesNumber;

}


float AbstractStockFund::getSharesNumber() const {
    return sharesNumber;
}

void AbstractStockFund::setSharesNumber(float shareNumber) {
    AbstractStockFund::sharesNumber = shareNumber;
}

float AbstractStockFund::getActualInvestment() const {
    return actualInvestment;
}

void AbstractStockFund::setActualInvestment(float actualInvestment) {
    AbstractStockFund::actualInvestment = actualInvestment;
}
