#include "gtest/gtest.h"

#include "../Model.h"

TEST(Model, Model_do_transaction) {

	Transaction t1(true, "", "IT1111111111111111111111111", "Mario", "IT2222222222222222222222222", 200, "bicicletta",
	               QDate::currentDate());

	Model model;

	ASSERT_EQ(model.doTransaction(t1), 1);

	t1 = Transaction(true, "Alessandro M", "IT111", "Mario L", "IT222", 200, "bicicletta", QDate::currentDate());

	ASSERT_EQ(model.doTransaction(t1), 2);

	t1 = Transaction(true, "Alessandro M", "IT1111111111111111111111111", "", "IT222", 200, "bicicletta",
	                 QDate::currentDate());

	ASSERT_EQ(model.doTransaction(t1), 3);

	t1 = Transaction(true, "Alessandro M", "IT1111111111111111111111111", "Mario L", "IT222", 200, "bicicletta",
	                 QDate::currentDate());

	ASSERT_EQ(model.doTransaction(t1), 4);

	t1 = Transaction(true, "Alessandro M", "IT1111111111111111111111111", "Mario L", "IT2222222222222222222222222", 0,
	                 "bicicletta", QDate::currentDate());

	ASSERT_EQ(model.doTransaction(t1), 5);

	t1 = Transaction(true, "Alessandro M", "IT1111111111111111111111111", "Mario L", "IT2222222222222222222222222",
	                 2000000000, "bicicletta", QDate::currentDate());

	ASSERT_EQ(model.doTransaction(t1), 6);

}

TEST(Model, Model_save_account) {

	Model model;

	std::map<AccountData, QString> strings;

	strings.insert(std::make_pair(AccountData::name, ""));
	strings.insert(std::make_pair(AccountData::surname, "Maggio"));
	strings.insert(std::make_pair(AccountData::codiceFiscale, "MGGLSNAAAAAAAAAA"));
	strings.insert(std::make_pair(AccountData::city, "Pistoia"));
	strings.insert(std::make_pair(AccountData::CAP, "51100"));
	strings.insert(std::make_pair(AccountData::address, "Via Garibaldi"));
	strings.insert(std::make_pair(AccountData::phoneNumber, "3339995566"));
	strings.insert(std::make_pair(AccountData::mail, "mail@gmail.com"));

	ASSERT_EQ(model.saveAccount(strings), 1);

	strings.clear();
	strings.insert(std::make_pair(AccountData::name, "Aleesandro"));
	strings.insert(std::make_pair(AccountData::surname, ""));
	strings.insert(std::make_pair(AccountData::codiceFiscale, "MGGLSNAAAAAAAAAA"));
	strings.insert(std::make_pair(AccountData::city, "Pistoia"));
	strings.insert(std::make_pair(AccountData::CAP, "51100"));
	strings.insert(std::make_pair(AccountData::address, "Via Garibaldi"));
	strings.insert(std::make_pair(AccountData::phoneNumber, "3339995566"));
	strings.insert(std::make_pair(AccountData::mail, "mail@gmail.com"));

	ASSERT_EQ(model.saveAccount(strings), 2);

	strings.clear();
	strings.insert(std::make_pair(AccountData::name, "Aleesandro"));
	strings.insert(std::make_pair(AccountData::surname, "Maggio"));
	strings.insert(std::make_pair(AccountData::codiceFiscale, "MGGLSNAAAA"));
	strings.insert(std::make_pair(AccountData::city, "Pistoia"));
	strings.insert(std::make_pair(AccountData::CAP, "51100"));
	strings.insert(std::make_pair(AccountData::address, "Via Garibaldi"));
	strings.insert(std::make_pair(AccountData::phoneNumber, "3339995566"));
	strings.insert(std::make_pair(AccountData::mail, "mail@gmail.com"));

	ASSERT_EQ(model.saveAccount(strings), 3);

	strings.clear();
	strings.insert(std::make_pair(AccountData::name, "Aleesandro"));
	strings.insert(std::make_pair(AccountData::surname, "Maggio"));
	strings.insert(std::make_pair(AccountData::codiceFiscale, "MGGLSNAAAAAAAAAA"));
	strings.insert(std::make_pair(AccountData::city, ""));
	strings.insert(std::make_pair(AccountData::CAP, "51100"));
	strings.insert(std::make_pair(AccountData::address, "Via Garibaldi"));
	strings.insert(std::make_pair(AccountData::phoneNumber, "3339995566"));
	strings.insert(std::make_pair(AccountData::mail, "mail@gmail.com"));

	ASSERT_EQ(model.saveAccount(strings), 4);

	strings.clear();
	strings.insert(std::make_pair(AccountData::name, "Aleesandro"));
	strings.insert(std::make_pair(AccountData::surname, "Maggio"));
	strings.insert(std::make_pair(AccountData::codiceFiscale, "MGGLSNAAAAAAAAAA"));
	strings.insert(std::make_pair(AccountData::city, "Pistoia"));
	strings.insert(std::make_pair(AccountData::CAP, ""));
	strings.insert(std::make_pair(AccountData::address, "Via Garibaldi"));
	strings.insert(std::make_pair(AccountData::phoneNumber, "3339995566"));
	strings.insert(std::make_pair(AccountData::mail, "mail@gmail.com"));

	ASSERT_EQ(model.saveAccount(strings), 5);

	strings.clear();
	strings.insert(std::make_pair(AccountData::name, "Aleesandro"));
	strings.insert(std::make_pair(AccountData::surname, "Maggio"));
	strings.insert(std::make_pair(AccountData::codiceFiscale, "MGGLSNAAAAAAAAAA"));
	strings.insert(std::make_pair(AccountData::city, "Pistoia"));
	strings.insert(std::make_pair(AccountData::CAP, "51100"));
	strings.insert(std::make_pair(AccountData::address, ""));
	strings.insert(std::make_pair(AccountData::phoneNumber, "3339995566"));
	strings.insert(std::make_pair(AccountData::mail, "mail@gmail.com"));

	ASSERT_EQ(model.saveAccount(strings), 6);

	strings.clear();
	strings.insert(std::make_pair(AccountData::name, "Aleesandro"));
	strings.insert(std::make_pair(AccountData::surname, "Maggio"));
	strings.insert(std::make_pair(AccountData::codiceFiscale, "MGGLSNAAAAAAAAAA"));
	strings.insert(std::make_pair(AccountData::city, "Pistoia"));
	strings.insert(std::make_pair(AccountData::CAP, "51100"));
	strings.insert(std::make_pair(AccountData::address, "Via Garibaldi"));
	strings.insert(std::make_pair(AccountData::phoneNumber, ""));
	strings.insert(std::make_pair(AccountData::mail, "mail@gmail.com"));

	ASSERT_EQ(model.saveAccount(strings), 7);

	strings.clear();
	strings.insert(std::make_pair(AccountData::name, "Aleesandro"));
	strings.insert(std::make_pair(AccountData::surname, "Maggio"));
	strings.insert(std::make_pair(AccountData::codiceFiscale, "MGGLSNAAAAAAAAAA"));
	strings.insert(std::make_pair(AccountData::city, "Pistoia"));
	strings.insert(std::make_pair(AccountData::CAP, "51100"));
	strings.insert(std::make_pair(AccountData::address, "Via Garibaldi"));
	strings.insert(std::make_pair(AccountData::phoneNumber, "3339995566"));
	strings.insert(std::make_pair(AccountData::mail, "mailgmail"));

	ASSERT_EQ(model.saveAccount(strings), 8);

}

TEST(Model, Model_do_investment) {

	Model model;

	auto conto = dynamic_cast<Conto *>(model.accessDataStorage("Conto"));

	conto->setLiquid(1000);

	auto investment = new Bond;
	investment->setTotalInvested(3000);

	int e = model.doInvestment(investment);

	ASSERT_EQ(e, 1);

}

TEST(Model, Model_Error_log) {

	Model model;

	model.makeMessageDialogNoButtons("ERRORE", "testo dell'errore");

	ASSERT_TRUE(model.getErrorLog()->getTitle() == "ERRORE");
	ASSERT_TRUE(model.getErrorLog()->getText() == "testo dell'errore");

}