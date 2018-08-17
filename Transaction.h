//
// Created by alessandro on 16/08/18.
//

#ifndef FINANCIALMANAGER_TRANSACTIONS_H
#define FINANCIALMANAGER_TRANSACTIONS_H


#include <QtCore/QDate>


class Transaction {
public:

  Transaction(bool d, QString pN, QString pI, QString rN, QString rI, int a, QString c , QDate dat):debit(d),payerName(pN), payerIBAN(pI), receiverName(rN), receiverIBAN(rI), amount(a), causal(c), date(dat){}


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

    const QDate &getDate() const {
        return date;
    }

protected:

    bool debit;
    QString payerName;
    QString payerIBAN;
    QString receiverName;
    QString receiverIBAN;
    int amount;
    QString causal;
    QDate date;

};


#endif //FINANCIALMANAGER_TRANSACTIONS_H
