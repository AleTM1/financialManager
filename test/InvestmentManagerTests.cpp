#include "gtest/gtest.h"
#include "../InvestmentManager.h"
#include "../CompaniesList.h"
TEST(InvestmentManager, InvestmentManager_save_and_load) {
  InvestmentManager investmentManager;
  CompaniesList companiesList;

  //salvo i dati già inseriti

  std::list<Investment *> orignalData;
  for (auto &e:investmentManager.getInvestmentList())
    orignalData.push_back(e);

  //simulo nuovi dati

  investmentManager.clear();
  auto stock = new Stock;
  stock->setSharesNumber(3);
  stock->setBuyDate(QDate::currentDate());
  stock->setInvestorIBAN("ITAAA");
  stock->setInvestorName("Mario");
  stock->setCompany(companiesList.companies[0]);
  investmentManager.addInvestment(stock);
  auto stock1 = new Stock;
  stock1->setSharesNumber(2);
  stock1->setBuyDate(QDate::currentDate());
  stock1->setInvestorIBAN("ITBBB");
  stock1->setInvestorName("Luigi");
  stock1->setCompany(companiesList.companies[1]);
  investmentManager.addInvestment(stock1);
  auto bond = new Bond;
  bond->setCompany(companiesList.companies[2]);
  bond->setInvestorName("Ugo");
  bond->setInvestorIBAN("ITCCC");
  bond->setBuyDate(QDate::currentDate());
  bond->setMonthsDuration(6, true);
  bond->setTotalInvested(3000);
  investmentManager.addInvestment(stock1);
  investmentManager.addInvestment(bond);


  //simulo nuova apertura

  InvestmentManager investmentManager1;
  investmentManager1.loadData();
  auto i_first = investmentManager1.getInvestmentList().front();
  auto i_last = investmentManager1.getInvestmentList().back();
  ASSERT_TRUE(i_first->getInvestmentType()==InvestmentType::stock);
  ASSERT_TRUE(abs(i_first->getTotalInvested() - 3*1221.57) < 0.0001);
  ASSERT_TRUE(i_first->getCompany()->getISIN()=="DE000A11RNQ5");
  ASSERT_TRUE(i_first->getBuyDate()==QDate::currentDate());
  ASSERT_TRUE(i_first->getInvestorName()=="Mario");
  ASSERT_TRUE(i_first->getInvestorIBAN()=="ITAAA");
  ASSERT_TRUE(dynamic_cast<Stock *>(i_first)->getSharesNumber()==3);
  ASSERT_TRUE(i_last->getInvestmentType()==InvestmentType::bond);
  ASSERT_TRUE(i_last->getTotalInvested()==3000);
  ASSERT_TRUE(i_last->getCompany()->getISIN()=="US5949181045");
  ASSERT_TRUE(i_last->getBuyDate()==QDate::currentDate());
  ASSERT_TRUE(i_last->getInvestorName()=="Ugo");
  ASSERT_TRUE(i_last->getInvestorIBAN()=="ITCCC");
  ASSERT_TRUE(dynamic_cast<Bond *>(i_last)->getMonthsDuration()==6);

  //ripristina

  investmentManager.clear();
  for (auto &e:orignalData)
    investmentManager.addInvestment(e);
}

TEST(InvestmentManager, InvestmentManager_remove_element) {
  InvestmentManager investmentManager;
  CompaniesList companiesList;

  //salvo i dati già inseriti

  std::list<Investment *> orignalData;
  for (auto &e:investmentManager.getInvestmentList())
    orignalData.push_back(e);

  //simulo nuovi dati

  investmentManager.clear();
  auto stock1 = new Stock;
  stock1->setSharesNumber(2);
  stock1->setBuyDate(QDate::currentDate());
  stock1->setInvestorIBAN("ITBBB");
  stock1->setInvestorName("Luigi");
  stock1->setCompany(companiesList.companies[1]);
  investmentManager.addInvestment(stock1);
  auto stock = new Stock;
  stock->setSharesNumber(3);
  stock->setBuyDate(QDate::currentDate());
  stock->setInvestorIBAN("ITAAA");
  stock->setInvestorName("Mario");
  stock->setCompany(companiesList.companies[0]);
  investmentManager.addInvestment(stock);
  auto bond = new Bond;
  bond->setCompany(companiesList.companies[2]);
  bond->setInvestorName("Ugo");
  bond->setInvestorIBAN("ITCCC");
  bond->setBuyDate(QDate::currentDate());
  bond->setMonthsDuration(6, true);
  bond->setTotalInvested(3000);
  investmentManager.addInvestment(stock1);
  investmentManager.addInvestment(bond);


  //simulo nuova apertura

  InvestmentManager investmentManager1;
  investmentManager1.loadData();
  auto i_rem = investmentManager1.getInvestmentList().begin();
  investmentManager1.removeInvestment(i_rem);
  auto i_first = investmentManager1.getInvestmentList().front();
  auto i_last = investmentManager1.getInvestmentList().back();
  ASSERT_TRUE(i_first->getInvestmentType()==InvestmentType::stock);
  ASSERT_TRUE(abs(i_first->getTotalInvested() - 3*1221.57) < 0.0001);
  ASSERT_TRUE(i_first->getCompany()->getISIN()=="DE000A11RNQ5");
  ASSERT_TRUE(i_first->getBuyDate()==QDate::currentDate());
  ASSERT_TRUE(i_first->getInvestorName()=="Mario");
  ASSERT_TRUE(i_first->getInvestorIBAN()=="ITAAA");
  ASSERT_TRUE(dynamic_cast<Stock *>(i_first)->getSharesNumber()==3);
  ASSERT_TRUE(i_last->getInvestmentType()==InvestmentType::bond);
  ASSERT_TRUE(i_last->getTotalInvested()==3000);
  ASSERT_TRUE(i_last->getCompany()->getISIN()=="US5949181045");
  ASSERT_TRUE(i_last->getBuyDate()==QDate::currentDate());
  ASSERT_TRUE(i_last->getInvestorName()=="Ugo");
  ASSERT_TRUE(i_last->getInvestorIBAN()=="ITCCC");
  ASSERT_TRUE(dynamic_cast<Bond *>(i_last)->getMonthsDuration()==6);


  //ripristina

  investmentManager.clear();
  for (auto &e:orignalData)
    investmentManager.addInvestment(e);
}

