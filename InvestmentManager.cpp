//
// Created by alessandro on 26/08/18.
//

#include "InvestmentManager.h"

InvestmentManager::InvestmentManager() {

    groupName = "InvestmentManager";

}

InvestmentManager::~InvestmentManager() {

    for (auto e:investmentList)
        delete e;

    investmentList.clear();

}



void InvestmentManager::addInvestment(Investment *investment) {

    investmentList.push_back(investment);

    saveData();

}


void InvestmentManager::saveData() {

    data.beginGroup(groupName + "/localInvestments");

    data.beginWriteArray("investment", investmentList.size());

    Stock* stock;
    Bond* bond;
    Fund* fund;

    int i = 0;
    for (auto &investment : investmentList) {
        data.setArrayIndex(i);

        data.setValue(QString::number(InvestmentData::investmentType),investment->getInvestmentType());
        data.setValue(QString::number(InvestmentData::totalInvested),investment->getTotalInvested());
        data.setValue(QString::number(InvestmentData::ISIN),investment->getEntity()->getISIN());
        data.setValue(QString::number(InvestmentData::entityName),investment->getEntity()->getName());
        data.setValue(QString::number(InvestmentData::investorIBAN),investment->getInvestorIBAN());
        data.setValue(QString::number(InvestmentData::investorName),investment->getInvestorName());

        stock = dynamic_cast<Stock*>(investment);
        fund = dynamic_cast<Fund*>(investment);
        bond = dynamic_cast<Bond*>(investment);
        if(stock || fund ){

            if (stock) {
                data.setValue(QString::number(StockFundData::actualInvestment), stock->getActualInvestment());
                data.setValue(QString::number(StockFundData::sharesNum), stock->getSharesNumber());
            }else{
                data.setValue(QString::number(StockFundData::actualInvestment), fund->getActualInvestment());
                data.setValue(QString::number(StockFundData::sharesNum), fund->getSharesNumber());
            }
        }else if (bond){

            data.setValue(QString::number(BondData ::deadline), bond->getDeadlineDate());
            data.setValue(QString::number(BondData ::monthsNumber), bond->getMonthsDuration());

        }

        i++;
    }

    data.endArray();

    data.endGroup();


    data.sync();

}


void InvestmentManager::loadData() {

    investmentList.clear();

    data.beginGroup(groupName + "/localInvestments");

    int size = data.beginReadArray("investment");

    for (int i = 0; i < size; i++) {

        data.setArrayIndex(i);
        if(data.value(QString::number(InvestmentData::investmentType)) == InvestmentType::stock){
            auto investment = new Stock(data.value(QString::number(StockFundData::sharesNum)).toFloat());
            investment->setActualInvestment(data.value(QString::number(StockFundData::actualInvestment)).toFloat());
            commonLoad(investment);
        }else if(data.value(QString::number(InvestmentData::investmentType)) == InvestmentType::fund){
            auto investment = new Fund(data.value(QString::number(StockFundData::sharesNum)).toFloat());
            investment->setActualInvestment(data.value(QString::number(StockFundData::actualInvestment)).toFloat());
            commonLoad(investment);
        }else if(data.value(QString::number(InvestmentData::investmentType)) == InvestmentType::bond){
            auto investment = new Bond(data.value(QString::number(BondData::monthsNumber)).toInt());
            investment->setDeadlineDate(data.value(QString::number(BondData::deadline)).toDate());
            commonLoad(investment);
        }


    }

    data.endArray();

    data.endGroup();

    data.sync();


}



//--------------------private Methods


void InvestmentManager::commonLoad(Investment* investment){

    investment->setInvestorIBAN(data.value(QString::number(InvestmentData::investorIBAN)).toString());
    investment->setInvestorName(data.value(QString::number(InvestmentData::investorName)).toString());
    investment->setTotalInvested(data.value(QString::number(InvestmentData::totalInvested)).toFloat());

    for (auto e:investmentList)
        if(e->getEntity()->getISIN() == data.value(QString::number(InvestmentData::ISIN)).toString())
            investment->setEntity(e->getEntity());

    investmentList.push_back(investment);

}


//-----------------------

const std::list<Investment *> &InvestmentManager::getInvestmentList() const {
    return investmentList;
}



