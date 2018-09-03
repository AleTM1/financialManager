#include "gtest/gtest.h"

#include "../Model.h"

TEST(Model, Model_do_transaction) {


    Transaction t1(true,"","IT1111111111111111111111111","Mario","IT2222222222222222222222222", 200,"bicicletta", QDate::currentDate());

    Model model;

    ASSERT_EQ(model.doTransaction(t1), 1);

    t1 = Transaction(true,"Alessandro M","IT111","Mario L","IT222", 200,"bicicletta", QDate::currentDate());

    ASSERT_EQ(model.doTransaction(t1), 2);

    t1 = Transaction(true,"Alessandro M","IT1111111111111111111111111","","IT222", 200,"bicicletta", QDate::currentDate());

    ASSERT_EQ(model.doTransaction(t1), 3);

    t1 = Transaction(true,"Alessandro M","IT1111111111111111111111111","Mario L","IT222", 200,"bicicletta", QDate::currentDate());

    ASSERT_EQ(model.doTransaction(t1), 4);

    t1 = Transaction(true,"Alessandro M","IT1111111111111111111111111","Mario L","IT2222222222222222222222222", 0,"bicicletta", QDate::currentDate());

    ASSERT_EQ(model.doTransaction(t1), 5);

    t1 = Transaction(true,"Alessandro M","IT1111111111111111111111111","Mario L","IT2222222222222222222222222", 2000000000,"bicicletta", QDate::currentDate());

    ASSERT_EQ(model.doTransaction(t1), 6);


}