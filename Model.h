//
// Created by alessandro on 07/08/18.
//

#ifndef QTPROVA_MODEL_H
#define QTPROVA_MODEL_H
#include "Subject.h"
#include "Account.h"
#include "Historical.h"
#include "ErrorLog.h"
#include "CompaniesList.h"
#include "InvestmentManager.h"

class Model : public Subject {
 public:
  Model();
  ~Model();
  bool isFirstOpening();
  void createAccount();
  void loadAll();
  void clearAll();
  int saveAccount(std::map<AccountData, QString>);
  void saveConto(QString);
  int doTransaction(Transaction transaction);
  void makeMessageDialogNoButtons(QString ttl, QString txt);
  void changeHistoricalOrder(ResearchOptions);
  const CompaniesList &getEntitiesList() const;
  int doInvestment(Investment *investment);
  void updateInvestmentValue();
  void removeInvestment(int);
 public:
  bool isTabAccountLocked() const;
  void setTabAccountLocked(bool tabAccountLocked);
  AbstractDataStorage *accessDataStorage(QString) const;
  ErrorLog *getErrorLog() const;
 private:
  bool tabAccountLocked;
  Account *account;
  Conto *conto;
  Historical *historical;
  CompaniesList companiesList;
  InvestmentManager *investmentManager;
  std::vector<AbstractDataStorage *> dataStorages;
  ErrorLog *errorLog = nullptr;
};
#endif //QTPROVA_MODEL_H
