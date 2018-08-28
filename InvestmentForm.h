//
// Created by alessandro on 28/08/18.
//

#ifndef FINANCIALMANAGER_INVESTMENTFORM_H
#define FINANCIALMANAGER_INVESTMENTFORM_H


#include "Ui_investmentForm.h"

class InvestmentForm : public QWidget {
    Q_OBJECT
public:

    InvestmentForm():ui_investmentForm(new Ui_investmentForm){ui_investmentForm->setupUi(this);}

    ~InvestmentForm(){delete ui_investmentForm;}

public:

    Ui_investmentForm* ui_investmentForm;

};


#endif //FINANCIALMANAGER_INVESTMENTFORM_H
