#include "gtest/gtest.h"

#include "../Bond.h"

TEST(Bond, Bond_deadline_date) {

	auto bond = new Bond;

	bond->setBuyDate(QDate(18, 3, 15));
	bond->setMonthsDuration(6, true);

	ASSERT_TRUE(bond->getDeadlineDate() == QDate(18, 9, 15));

	bond->setBuyDate(QDate(18, 3, 15));
	bond->setMonthsDuration(16, true);

	ASSERT_TRUE(bond->getDeadlineDate() == QDate(19, 7, 15));

	delete bond;

}