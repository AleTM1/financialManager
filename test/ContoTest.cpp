#include "gtest/gtest.h"

#include "../Conto.h"

TEST(Conto, Conto_ContoGenerator_Test) {

    Conto conto;

    conto.contoGenerator();

    ASSERT_EQ(conto.getInvested(),0);
    ASSERT_EQ(conto.getLiquid(),20000);
    ASSERT_EQ(conto.getSaldo(),20000);
    ASSERT_EQ(conto.getTitle(),"Conto corrente");

    std::string string=conto.getIBAN().toStdString();


    //cifre dell'IBAN corrette
    for (int i=0; i<25;i++) {

        if(i!=2)
        ASSERT_TRUE(string[i+2] < 10 && string[i+2] >= 0);

    }
}
