//
// Created by alessandro on 07/08/18.
//


#include <QtCore/QFile>
#include <QtCore/QTextStream>
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

        viewWindow->tabWidget->setCurrentIndex(1);

        for(int i=0; i<viewWindow->tabWidget->count(); i++)
            if(viewWindow->tabWidget->currentIndex() != i)
                viewWindow->tabWidget->setTabEnabled(i,false);

    }else {

        //-----------ACCOUNT-------------

        viewWindow->textEdit_Name->setEnabled(false);
        viewWindow->textEdit_Surname->setEnabled(false);

        for(int i=0; i<viewWindow->tabWidget->count(); i++)
                viewWindow->tabWidget->setTabEnabled(i,true);

        viewWindow->textEdit_Name->setText(model->accessAccount()->getName());
        viewWindow->textEdit_Surname->setText(model->accessAccount()->getSurname());
        viewWindow->textEdit_city->setText(model->accessAccount()->getCity());
        viewWindow->textEdit_CAP->setText(model->accessAccount()->getCAP());
        viewWindow->textEdit_Address->setText(model->accessAccount()->getAddress());
        viewWindow->textEdit_PhoneNumber->setText(model->accessAccount()->getPhoneNumber());
        viewWindow->textEdit_Mail->setText(model->accessAccount()->getMail());

        //-------------CONTO----------------------

        viewWindow->label_title->setText(model->accessConto()->getTitle());
        viewWindow->lineEdit_title->setText( viewWindow->label_title->text());

    }


}

void View::closeApp() {
   QApplication::exit(0);
}

void View::showTitleEdit() {

   viewWindow->horizontalWidget_title->setVisible(!viewWindow->horizontalWidget_title->isVisible());

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

    std::map<std::string, QString> strings;

    strings.insert(std::make_pair("title",viewWindow->lineEdit_title->text()));

    controller->contoSave(strings);

    showTitleEdit();

}




//--------------------------