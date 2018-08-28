//
// Created by alessandro on 25/08/18.
//

#include "Stock.h"


Stock::Stock() {

    investmentType = stock;

}

void Stock::totalInvestmentCalculator() {

    totalInvested = company->getShareCost() * sharesNumber;
    actualInvestment = totalInvested;

}


float Stock::getSharesNumber() const {
    return sharesNumber;
}

void Stock::setSharesNumber(float shareNumber) {
    Stock::sharesNumber = shareNumber;
}

float Stock::getActualInvestment() const {
    return actualInvestment;
}

void Stock::setActualInvestment(float actualInvestment) {
    Stock::actualInvestment = actualInvestment;
}

void Stock::setEntity(Company *entity) {
    Investment::company = entity;
    totalInvestmentCalculator();
}

void Stock::showEntityDetails() {

}
