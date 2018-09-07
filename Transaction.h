//
// Created by alessandro on 16/08/18.
//

#ifndef FINANCIALMANAGER_TRANSACTIONS_H
#define FINANCIALMANAGER_TRANSACTIONS_H
#include <QtCore/QDate>

class Transaction {
 public:
  Transaction(bool d, QString pN, QString pI, QString rN, QString rI, float a, QString c, QDate dat)
      : debit(d), payerName(pN), payerIBAN(pI), receiverName(rN), receiverIBAN(rI), amount(a), causal(c), date(dat) {}

  bool operator==(const Transaction &orig) {
    return (orig.getPayerName()==payerName && orig.getReceiverName()==receiverName && orig.getPayerIBAN()==payerIBAN
        && orig.getReceiverIBAN()==receiverIBAN && orig.getAmount()==amount && orig.getCausal()==causal
        && orig.getDate()==date && orig.isDebit()==debit);
  }

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

  float getAmount() const {
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
  float amount;
  QString causal;
  QDate date;
};
#endif //FINANCIALMANAGER_TRANSACTIONS_H
