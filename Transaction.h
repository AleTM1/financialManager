//
// Created by alessandro on 16/08/18.
//

#ifndef FINANCIALMANAGER_TRANSACTIONS_H
#define FINANCIALMANAGER_TRANSACTIONS_H


#include "Conto.h"
#include "Historical.h"

class Transaction {
public:

  Transaction(bool d, QString pN, QString pI, QString rN, QString rI, int a, QString c ):debit(d),payerName(pN), payerIBAN(pI), receiverName(rN), receiverIBAN(rI), amount(a), causal(c){}


    bool isDebit() const {
        return debit;
    }

    const QString &getPayerName() const {
        return payerName;
    }

    const QString &getPayerIBAN() const {
        return payerIBAN;
    }

    const QString &getReceiverName() const {
        return receiverName;
    }

    const QString &getReceiverIBAN() const {
        return receiverIBAN;
    }

    int getAmount() const {
        return amount;
    }

    const QString &getCausal() const {
        return causal;
    }

protected:

    bool debit;
    QString payerName;
    QString payerIBAN;
    QString receiverName;
    QString receiverIBAN;
    int amount;
    QString causal;

};


#endif //FINANCIALMANAGER_TRANSACTIONS_H
