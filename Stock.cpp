//
// Created by alessandro on 25/08/18.
//

#include "Stock.h"

Stock::Stock() {

    investmentType = stock;

}

void Stock::totalInvestmentCalculator() {

    totalInvested = company->getShareCost()*sharesNumber;

}

float Stock::getSharesNumber() const {

    return sharesNumber;
}

void Stock::setSharesNumber(float shareNumber) {

    Stock::sharesNumber = shareNumber;
}

void Stock::setCompany(Company* entity) {

    Investment::company = entity;
    totalInvestmentCalculator();

}

