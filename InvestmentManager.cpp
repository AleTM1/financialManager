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
  Stock *stock;
  Bond *bond;
  int i = 0;
  for (auto &investment : investmentList) {
    data.setArrayIndex(i);
    QString investmentType;
    if (investment->getInvestmentType()==InvestmentType::stock) {
      investmentType = "Azione";
    } else if (investment->getInvestmentType()==InvestmentType::bond) {
      investmentType = "Obbligazione";
    }
    data.setValue(QString::number(InvestmentData::investmentType), investmentType);
    data.setValue(QString::number(InvestmentData::totalInvested), investment->getTotalInvested());
    data.setValue(QString::number(InvestmentData::ISIN), investment->getCompany()->getISIN());
    data.setValue(QString::number(InvestmentData::entityName), investment->getCompany()->getName());
    data.setValue(QString::number(InvestmentData::investorIBAN), investment->getInvestorIBAN());
    data.setValue(QString::number(InvestmentData::investorName), investment->getInvestorName());
    data.setValue(QString::number(InvestmentData::buyDate), investment->getBuyDate());
    stock = dynamic_cast<Stock *>(investment);
    bond = dynamic_cast<Bond *>(investment);
    if (stock) {
      data.setValue(QString::number(InvestmentData::stockSharesNum), stock->getSharesNumber());
    } else if (bond) {
      data.setValue(QString::number(InvestmentData::bondDeadline), bond->getDeadlineDate());
      data.setValue(QString::number(InvestmentData::bondMonthsNumber), bond->getMonthsDuration());
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
    Investment *investment;
    if (data.value(QString::number(InvestmentData::investmentType)).toString()=="Azione") {
      investment = new Stock;
      dynamic_cast<Stock *>(investment)->setSharesNumber(data.value(QString::number(InvestmentData::stockSharesNum)).toFloat());
    } else if (data.value(QString::number(InvestmentData::investmentType)).toString()=="Obbligazione") {
      investment = new Bond;
      dynamic_cast<Bond *>(investment)->setMonthsDuration(data.value(QString::number(InvestmentData::bondMonthsNumber)).toInt(),
                                                          false);
      dynamic_cast<Bond *>(investment)->setDeadlineDate(data.value(QString::number(InvestmentData::bondDeadline)).toDate());
    }
    investment->setInvestorIBAN(data.value(QString::number(InvestmentData::investorIBAN)).toString());
    investment->setInvestorName(data.value(QString::number(InvestmentData::investorName)).toString());
    investment->setTotalInvested(data.value(QString::number(InvestmentData::totalInvested)).toFloat());
    investment->setBuyDate(data.value(QString::number(InvestmentData::buyDate)).toDate());
    for (auto e:companiesList.companies)
      if (e->getISIN()==data.value(QString::number(InvestmentData::ISIN))) {
        investment->setCompany(e);
      }
    investmentList.push_back(investment);
  }
  data.endArray();
  data.endGroup();
  data.sync();
  checkForExpiredBonds();
}



//--------------------private Methods


void InvestmentManager::checkForExpiredBonds() {
  for (auto it = investmentList.begin(); it!=investmentList.end(); it++)
    if ((*it)->getInvestmentType()==InvestmentType::bond
        && dynamic_cast<Bond *>((*it))->getDeadlineDate()==QDate::currentDate()) {
      removeInvestment(it);
    }
}

//-----------------------

const std::list<Investment *> &InvestmentManager::getInvestmentList() const {
  return investmentList;
}

void InvestmentManager::removeInvestment(std::_List_const_iterator<Investment *> it) {
  investmentList.erase(it);
  saveData();
}



