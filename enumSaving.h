//
// Created by alessandro on 22/08/18.
//

#ifndef FINANCIALMANAGER_ENUMSAVING_H
#define FINANCIALMANAGER_ENUMSAVING_H

enum AccountData {
	name, surname, codiceFiscale, city, CAP, address, phoneNumber, mail
};

enum ContoData {
	title, IBAN, saldo, liquid, invested
};

enum TransactionData {
	debit, payerName, payerIBAN, receiverName, receiverIBAN, amount, causal, date
};

#endif //FINANCIALMANAGER_ENUMSAVING_H
