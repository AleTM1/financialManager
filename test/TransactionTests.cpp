#include "gtest/gtest.h"

#include "../Transaction.h"

TEST(Transaction, Transaction_equal_operator_Test) {

    Transaction t1(true, "Alessandro", "IT111", "Mario", "IT222", 200, "bicicletta", QDate::currentDate());

    Transaction t1bis(true, "Alessandro", "IT111", "Mario", "IT222", 200, "bicicletta", QDate::currentDate());

    ASSERT_TRUE(t1==t1bis);

    t1 = Transaction(true, "Alessandro", "IT111", "Mario", "IT222", 200, "bicicletta", QDate::currentDate());

    Transaction t2(false, "Alessandro", "IT111", "Mario", "IT222", 200, "bicicletta", QDate::currentDate());

    ASSERT_FALSE(t1==t2);

    t1 = Transaction(true, "Alessandro", "IT111", "Mario", "IT222", 200, "bicicletta", QDate::currentDate());

    t2 = Transaction(true, "Giulio", "IT111", "Mario", "IT222", 200, "bicicletta", QDate::currentDate());

    ASSERT_FALSE(t1==t2);

    t1 = Transaction(true, "Alessandro", "IT111", "Mario", "IT222", 200, "bicicletta", QDate::currentDate());

    t2 = Transaction(true, "Alessandro", "IT333", "Mario", "IT222", 200, "bicicletta", QDate::currentDate());

    ASSERT_FALSE(t1==t2);

    t1 = Transaction(true, "Alessandro", "IT111", "Mario", "IT222", 200, "bicicletta", QDate::currentDate());

    t2 = Transaction(true, "Alessandro", "IT111", "Giulio", "IT222", 200, "bicicletta", QDate::currentDate());

    ASSERT_FALSE(t1==t2);

    t1 = Transaction(true, "Alessandro", "IT111", "Mario", "IT222", 200, "bicicletta", QDate::currentDate());

    t2 = Transaction(true, "Alessandro", "IT111", "Mario", "IT333", 200, "bicicletta", QDate::currentDate());

    ASSERT_FALSE(t1==t2);

    t1 = Transaction(true, "Alessandro", "IT111", "Mario", "IT222", 200, "bicicletta", QDate::currentDate());

    t2 = Transaction(true, "Alessandro", "IT111", "Mario", "IT222", 400, "bicicletta", QDate::currentDate());

    ASSERT_FALSE(t1==t2);

    t1 = Transaction(true, "Alessandro", "IT111", "Mario", "IT222", 200, "bicicletta", QDate::currentDate());

    t2 = Transaction(true, "Alessandro", "IT111", "Mario", "IT222", 200, "automobile", QDate::currentDate());

    ASSERT_FALSE(t1==t2);

    t1 = Transaction(true, "Alessandro", "IT111", "Mario", "IT222", 200, "bicicletta", QDate::currentDate());

    t2 = Transaction(true, "Alessandro", "IT111", "Mario", "IT222", 200, "bicicletta", QDate(17, 2, 3));

    ASSERT_FALSE(t1==t2);

}
