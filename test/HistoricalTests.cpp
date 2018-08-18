#include "gtest/gtest.h"

#include "../Historical.h"

TEST(Historical, Historical_save_and_load) {

    Historical historical;

    Transaction t1(true,"ale","IT111","mario","IT222", 200,"bicicletta", QDate::currentDate());
    Transaction t2(false,"alessandro","ITaaa","luigi","ITbbb", 1000,"auto", QDate::currentDate());

    historical.addTransaction(t1);
    historical.addTransaction(t2);

    Historical historical2;
    historical2.loadData();

    ASSERT_TRUE(t1 == historical2.getHistory()[0]);
    ASSERT_TRUE(t2 == historical2.getHistory()[1]);


}
