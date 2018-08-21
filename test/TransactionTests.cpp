#include "gtest/gtest.h"

#include "../Transaction.h"

TEST(Transaction, Transaction_equal_operator_Test) {

    Transaction t1(true,"ale","IT111","mario","IT222", 200,"bicicletta", QDate::currentDate());

    Transaction t1bis(true,"ale","IT111","mario","IT222", 200,"bicicletta", QDate::currentDate());



    ASSERT_TRUE(t1 == t1bis);


}
