//
// Created by alessandro on 25/08/18.
//

#include "FundSociety.h"

const std::list<Investment *> &FundSociety::getFundComposition() const {
    return fundComposition;
}

void FundSociety::setFundComposition(const std::list<Investment *> &fundComposition) {
    FundSociety::fundComposition = fundComposition;
}

float FundSociety::getCost() const {
    return cost;
}

void FundSociety::setCost(float cost) {
    FundSociety::cost = cost;
}

FundSociety::~FundSociety() {

    for (auto e:fundComposition)
        delete e;

    fundComposition.clear();

}

void FundSociety::generateComposition() {

}
