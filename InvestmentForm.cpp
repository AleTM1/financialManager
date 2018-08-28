//
// Created by alessandro on 28/08/18.
//

#include "InvestmentForm.h"

InvestmentForm::InvestmentForm(Controller* c, int i):controller(c), index(i), ui_investmentForm(new Ui_investmentForm){

    ui_investmentForm->setupUi(this);

}

InvestmentForm::~InvestmentForm(){
    delete ui_investmentForm;
}

void InvestmentForm::sell() {

    controller->sell(index);

}
