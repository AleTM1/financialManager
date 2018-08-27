//
// Created by alessandro on 25/08/18.
//

#include "Fund.h"

Fund::Fund(float sharesNum) : AbstractStockFund(sharesNum) {

    investmentType = fund;

}

void Fund::showEntityDetails() {

}


void Fund::totalInvestmentCalculator() {

    totalInvested = entity->getShareCost() * sharesNumber ;

    costAmount = totalInvested * ((dynamic_cast<FundSociety*>(entity)->getCost())/100);

}

float Fund::getCostAmount() const {
    return costAmount;
}


