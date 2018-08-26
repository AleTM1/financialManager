//
// Created by alessandro on 26/08/18.
//

#include "InvestmentManager.h"

InvestmentManager::InvestmentManager() {

    groupName = "InvestmentManager";

}

InvestmentManager::~InvestmentManager() {



}



void InvestmentManager::addInvestment(Investment *investment) {

    investmentList.push_back(investment);

    saveData();

}


void InvestmentManager::saveData() {

    //TODO SAVE

}


void InvestmentManager::loadData() {

}





//-----------------------

const std::list<Investment *> &InvestmentManager::getInvestmentList() const {
    return investmentList;
}



