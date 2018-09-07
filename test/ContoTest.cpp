#include "gtest/gtest.h"
#include "../Conto.h"
TEST(Conto, Conto_ContoGenerator_Test) {
  Conto conto;
  conto.contoGenerator();
  ASSERT_EQ(conto.getInvested(), 0);
  ASSERT_EQ(conto.getLiquid(), 20000);
  ASSERT_EQ(conto.getSaldo(), 20000);
  ASSERT_EQ(conto.getTitle(), "Conto corrente");
}

TEST(Conto, Conto_save_and_load) {
  Conto conto;
  conto.loadData();

  //conserva i dati già presenti

  QString origTitle = conto.getTitle();
  float origSaldo = conto.getSaldo();
  float origInvested = conto.getInvested();
  float origLiquid = conto.getLiquid();

  //simula un nuovo salvataggio

  conto.setTitle("Conto 1");
  conto.setSaldo(3020.5);
  conto.setLiquid(1520.5);
  conto.setInvested(1500);
  conto.saveData();

  //simula un nuovo accesso

  Conto conto1;
  conto1.loadData();
  ASSERT_TRUE(conto1.getTitle()=="Conto 1");
  ASSERT_TRUE(conto1.getSaldo()==3020.5);
  ASSERT_TRUE(conto1.getLiquid()==1520.5);
  ASSERT_TRUE(conto1.getInvested()==1500);
  ASSERT_FALSE(conto1.getTitle()=="Conto 2");
  ASSERT_FALSE(conto1.getSaldo()==3420.5);
  ASSERT_FALSE(conto1.getLiquid()==1720.5);
  ASSERT_FALSE(conto1.getInvested()==1500.6);


  //reinserisci i dati precedenti

  conto.setTitle(origTitle);
  conto.setSaldo(origSaldo);
  conto.setLiquid(origLiquid);
  conto.setInvested(origInvested);
  conto.saveData();
}

TEST(Conto, Conto_manage_saldo) {
  Conto conto;
  conto.setSaldo(3020.5);
  conto.setLiquid(1520.5);
  conto.setInvested(1500);
  conto.setLiquid(conto.getLiquid() + 2532);
  ASSERT_EQ(conto.getSaldo(), 5552.5);
  conto.setInvested(conto.getInvested() - 52.5);
  ASSERT_EQ(conto.getSaldo(), 5500.0);
}

TEST(Conto, Conto_Change_data) {
  Conto conto;
  conto.loadData();

  //conserva i dati già presenti

  QString origTitle = conto.getTitle();

  //simula un nuovo salvataggio

  conto.changeData("Conto 123");

  //simula un nuovo accesso

  Conto conto1;
  conto1.loadData();
  ASSERT_TRUE(conto1.getTitle()=="Conto 123");


  //reinserisci i dati precedenti

  conto.setTitle(origTitle);
  conto.saveData();
}