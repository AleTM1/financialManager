//
// Created by alessandro on 07/08/18.
//


#ifndef QTPROVA_VIEW_H
#define QTPROVA_VIEW_H
#include <QtWidgets/QMainWindow>
#include "Observer.h"
#include "Controller.h"
#include "ViewWindow.h"
#include "DialogNoButton.h"
#include "TransactionForm.h"
#include "InvestmentForm.h"

class View : public QMainWindow, public Observer {
 Q_OBJECT
 public:
  View(Controller *c, Model *m);
  virtual ~View();
  virtual void update() override;
  void refreshInvestmentValue();
 private slots:
  void closeApp();
  void RESET();
  void accountSave();
  void showTitleEdit();
  void showSearchOptions();
  void contoTitleSave();
  void radioButtonTransactionClicked();
  void doTransaction();
  void searchHistorical();
  void searchDateChanged();
  void cancel();
  void updateEntitesList();
  void updateInvestmentData();
  void lineInvestmentEdited(const QString &);
  void updateInvestmentAmount();
  void doInvestment();
  //----controlli---
  void lineIBANEdited(const QString &);
  void lineCAPEdited(const QString &);
  void lineAmountEdited(const QString &);
  void linePhoneNumber(const QString &);
  void codiceFiscaleEdited(const QString &);
  void onlyLetters(const QString &);
 private:
  void clearLayout(QLayout *layout);
  QString onlySelectedCharacters(QString &stringa, const QString &allowedCharacters);
  Account *updateAccount() const;
  Conto *updateConto() const;
  void updateTransaction(const Account *account, const Conto *conto) const;
  void updateHistorical();
  void updateInvestmentManager();
  void updateMessages();
  void lockAccountTab() const;
 private:
  Controller *controller;
  Model *model;
  Ui_MainWindow *viewWindow;
  DialogNoButton *dialogNoButton;
};
#endif //QTPROVA_VIEW_H
