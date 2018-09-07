//
// Created by alessandro on 28/08/18.
//

#ifndef FINANCIALMANAGER_INVESTMENTFORM_H
#define FINANCIALMANAGER_INVESTMENTFORM_H
#include "Ui_investmentForm.h"
#include "Controller.h"

class InvestmentForm : public QWidget {
 Q_OBJECT
 public:
  InvestmentForm(Controller *c, int i);
  ~InvestmentForm();
 public:
  Ui_investmentForm *ui_investmentForm;
 private slots:
  void sell();
 protected:
  Controller *controller;
  int index;
};
#endif //FINANCIALMANAGER_INVESTMENTFORM_H
