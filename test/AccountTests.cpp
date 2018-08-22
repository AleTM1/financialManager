#include "gtest/gtest.h"

#include "../Account.h"

TEST(Account, Account_save_and_load) {

    Account account;

    account.loadData();

    //conserva i dati già presenti
    
    std::map<AccountData, QString> orignalData;

    orignalData.insert(std::make_pair(name, account.getName()));
    orignalData.insert(std::make_pair(surname, account.getSurname()));
    orignalData.insert(std::make_pair(codiceFiscale, account.getCodiceFiscale()));
    orignalData.insert(std::make_pair(city, account.getCity()));
    orignalData.insert(std::make_pair(CAP, account.getCAP()));
    orignalData.insert(std::make_pair(address, account.getAddress()));
    orignalData.insert(std::make_pair(phoneNumber, account.getPhoneNumber()));
    orignalData.insert(std::make_pair(mail, account.getMail()));

    //simula un nuovo salvataggio

    std::map<AccountData, QString> nuovoSalvataggio;
    nuovoSalvataggio.insert(std::make_pair(name, "Mario"));
    nuovoSalvataggio.insert(std::make_pair(surname, "Rossi"));
    nuovoSalvataggio.insert(std::make_pair(codiceFiscale, "RSSMRI1234567890"));
    nuovoSalvataggio.insert(std::make_pair(city, "Pistoia"));
    nuovoSalvataggio.insert(std::make_pair(CAP, "51100"));
    nuovoSalvataggio.insert(std::make_pair(address, "Via Garibaldi"));
    nuovoSalvataggio.insert(std::make_pair(phoneNumber, "3337775511"));
    nuovoSalvataggio.insert(std::make_pair(mail, "mail@gmail.com"));

    account.changeData(nuovoSalvataggio);

    //simula un nuovo accesso
    
    Account account1;

    account1.loadData();

    ASSERT_TRUE(account1.getName() == "Mario");
    ASSERT_TRUE(account1.getSurname() == "Rossi");
    ASSERT_TRUE(account1.getCodiceFiscale() == "RSSMRI1234567890");
    ASSERT_TRUE(account1.getCity() == "Pistoia");
    ASSERT_TRUE(account1.getCAP() == "51100");
    ASSERT_TRUE(account1.getAddress() == "Via Garibaldi");
    ASSERT_TRUE(account1.getPhoneNumber() == "3337775511");
    ASSERT_TRUE(account1.getMail() == "mail@gmail.com");
    ASSERT_FALSE(account1.getName() == "Luigi");
    ASSERT_FALSE(account1.getSurname() == "Bianchi");
    ASSERT_FALSE(account1.getCodiceFiscale() == "BNCLGI1234567890");
    ASSERT_FALSE(account1.getCity() == "Firenze");
    ASSERT_FALSE(account1.getCAP() == "50100");
    ASSERT_FALSE(account1.getAddress() == "Via Roma");
    ASSERT_FALSE(account1.getPhoneNumber() == "3347772323");
    ASSERT_FALSE(account1.getMail() == "prova@gmail.com");

    //reinserisci i dati precedenti
    
    account.changeData(orignalData);

}
