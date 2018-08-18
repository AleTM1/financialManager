//
// Created by alessandro on 18/08/18.
//

#ifndef FINANCIALMANAGER_TRANSACTIONFORM_H
#define FINANCIALMANAGER_TRANSACTIONFORM_H


#include <QtWidgets/QWidget>
#include "transactionFormUi.h"

class TransactionForm : public QWidget {
    Q_OBJECT
public:

    TransactionForm():transactionForm_ui(new Ui_transactionForm){transactionForm_ui->setupUi(this);}


public:

    Ui_transactionForm* transactionForm_ui;

};

#endif //FINANCIALMANAGER_TRANSACTIONFORM_H
