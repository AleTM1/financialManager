//
// Created by alessandro on 07/08/18.
//


#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QDate>
#include "View.h"


View::View(Controller *c, Model *m):controller(c), model(m), viewWindow(new Ui_MainWindow) {

    viewWindow->setupUi(this);
    model->addObserver(this);
    controller->openingApp();

}



View::~View() {

    model->removeObserver(this);

    delete viewWindow;

}


void View::update() {

    if(model->isTabAccountLocked()){

        viewWindow->textEdit_Name->setEnabled(true);
        viewWindow->textEdit_Surname->setEnabled(true);

        viewWindow->tabWidget->setCurrentIndex(2);

        for(int i=0; i<viewWindow->tabWidget->count(); i++)
            if(viewWindow->tabWidget->currentIndex() != i)
                viewWindow->tabWidget->setTabEnabled(i,false);

    }else {

        //-----------ACCOUNT-------------

        viewWindow->textEdit_Name->setEnabled(false);
        viewWindow->textEdit_Surname->setEnabled(false);

        for(int i=0; i<viewWindow->tabWidget->count(); i++)
                viewWindow->tabWidget->setTabEnabled(i,true);

        auto account = dynamic_cast<Account*>(model->accessDataStorage("Account"));

        viewWindow->textEdit_Name->setText(account->getName());
        viewWindow->textEdit_Surname->setText(account->getSurname());
        viewWindow->textEdit_city->setText(account->getCity());
        viewWindow->textEdit_CAP->setText(account->getCAP());
        viewWindow->textEdit_Address->setText(account->getAddress());
        viewWindow->textEdit_PhoneNumber->setText(account->getPhoneNumber());
        viewWindow->textEdit_Mail->setText(account->getMail());

        //-------------CONTO----------------------

        auto conto = dynamic_cast<Conto*>(model->accessDataStorage("Conto"));


        viewWindow->label_title->setText(conto->getTitle());
        viewWindow->lineEdit_title->setText( viewWindow->label_title->text());

        viewWindow->label_IBAN->setText("IBAN: "+conto->getIBAN());
        viewWindow->label_Saldo->setText(QString::number(conto->getSaldo()));

        viewWindow->label_liquid->setText(" Liquidità: "+QString::number(conto->getLiquid()));
        viewWindow->label_invested->setText(" Investito: "+QString::number(conto->getInvested()));
        float pos = 100*static_cast<float>(conto->getLiquid())/static_cast<float>(conto->getSaldo());
        viewWindow->horizontalSlider_percetage->setSliderPosition(static_cast<int>(pos));


        //-------------Effettua Transazione---------------------

        viewWindow->label_currentDate->setText(QDate::currentDate().toString("dddd, dd / MMMM / yyyy"));

        if(viewWindow->radioButton_sendMoney->isChecked()){
            viewWindow->lineEdit_payerName->setText(account->getName() +" "+ account->getSurname());
            viewWindow->lineEdit_beneficiaryName->setText("");
            viewWindow->lineEdit_payerIBAN->setText(conto->getIBAN());
            viewWindow->lineEdit_beneficiaryIBAN->setText("");
            viewWindow->lineEdit_payerName->setEnabled(false);
            viewWindow->lineEdit_beneficiaryName->setEnabled(true);
            viewWindow->lineEdit_payerIBAN->setEnabled(false);
            viewWindow->lineEdit_beneficiaryIBAN->setEnabled(true);
        }else{
            viewWindow->lineEdit_beneficiaryName->setText(account->getName() +" "+ account->getSurname());
            viewWindow->lineEdit_payerName->setText("");
            viewWindow->lineEdit_beneficiaryIBAN->setText(conto->getIBAN());
            viewWindow->lineEdit_payerIBAN->setText("");
            viewWindow->lineEdit_payerName->setEnabled(true);
            viewWindow->lineEdit_beneficiaryName->setEnabled(false);
            viewWindow->lineEdit_payerIBAN->setEnabled(true);
            viewWindow->lineEdit_beneficiaryIBAN->setEnabled(false);
        }

    }


}

void View::closeApp() {
   QApplication::exit(0);
}

void View::showTitleEdit() {

   viewWindow->horizontalWidget_title->setVisible(!viewWindow->horizontalWidget_title->isVisible());

}

void View::radioButtonClicked() {
    update();
}


void View::RESET() {

    controller->reset();

}

//-------------------------------------
//SALVATAGGI

void View::accountSave() {

    std::map<std::string, QString> strings;

    strings.insert(std::make_pair("name",viewWindow->textEdit_Name->toPlainText()));
    strings.insert(std::make_pair("surname",viewWindow->textEdit_Surname->toPlainText()));
    strings.insert(std::make_pair("city",viewWindow->textEdit_city->toPlainText()));
    strings.insert(std::make_pair("CAP",viewWindow->textEdit_CAP->toPlainText()));
    strings.insert(std::make_pair("address",viewWindow->textEdit_Address->toPlainText()));
    strings.insert(std::make_pair("phoneNumber",viewWindow->textEdit_PhoneNumber->toPlainText()));
    strings.insert(std::make_pair("mail",viewWindow->textEdit_Mail->toPlainText()));

    if(model->isTabAccountLocked()){

        {
            controller->accountSave(strings);

        }

    }else{

        controller->accountSave(strings);

    }

}

void View::contoTitleSave() {

    controller->contoSave(viewWindow->lineEdit_title->text());

    showTitleEdit();

}




//--------------------------