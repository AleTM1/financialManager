//
// Created by alessandro on 08/08/18.
//

#ifndef FINANCIALMANAGER_ACCOUNT_H
#define FINANCIALMANAGER_ACCOUNT_H
#include <QtCore/QString>
#include <QtCore/QSettings>
#include "AbstractDataStorage.h"
#include "enumSaving.h"
class Account : public AbstractDataStorage {
 public:
  Account() { groupName = "Account"; }

  bool isFirstOpening();
  virtual void loadData() override;
  void changeData(std::map<AccountData, QString>);
  virtual void saveData() override;
 public:
  const QString &getName() const;
  const QString &getSurname() const;
  const QString &getCodiceFiscale() const;
  const QString &getCity() const;
  const QString &getCAP() const;
  const QString &getAddress() const;
  const QString &getPhoneNumber() const;
  const QString &getMail() const;
 protected:
  QString name;
  QString surname;
  QString codiceFiscale;
  QString city;
  QString CAP;
  QString address;
  QString phoneNumber;
  QString mail;
};
#endif //FINANCIALMANAGER_ACCOUNT_H
