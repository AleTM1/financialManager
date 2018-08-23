#include "gtest/gtest.h"

#include "../Historical.h"

TEST(Historical, Historical_save_and_load) {


    Historical historical;


    //salvo i dati già inseriti

    std::list<Transaction> orignalData;

    for(auto &e:historical.getHistory())
        orignalData.push_back(e);

    //simulo nuovi dati

    historical.clear();

    Transaction t1(true,"Alessandro M","IT111","Mario Rossi","IT222", 200,"bicicletta", QDate(18, 1, 2));

    Transaction t2(false,"Mario Rossi","ITGGG","Alessandro M","IT111", 2000,"auto", QDate(18, 3, 10));

    Transaction t3(false,"Luigi Bianchi","ITLLL","Alessandro M","IT111", 1450,"vacanza", QDate(18, 6, 15));

    historical.addTransaction(t1);
    historical.addTransaction(t2);
    historical.addTransaction(t3);

    //simulo nuova apertura

    Historical historical1;

    historical1.loadData();

    Transaction t_first = historical1.getHistory().front();
    Transaction t_last = historical1.getHistory().back();

    ASSERT_TRUE( t_first == t3);
    ASSERT_TRUE( t_last == t1);

    //ripristina

    historical.clear();

    for(auto &e:orignalData)
        historical.addTransaction(e);

}
