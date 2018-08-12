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

        viewWindow->tabWidget->setCurrentIndex(1);

        for(int i=0; i<viewWindow->tabWidget->count(); i++)
            if(viewWindow->tabWidget->currentIndex() != i)
                viewWindow->tabWidget->setTabEnabled(i,false);

    }else {

        viewWindow->textEdit_Name->setEnabled(false);
        viewWindow->textEdit_Surname->setEnabled(false);

        viewWindow->textEdit_Name->setText(model->accessAccount()->getName());
        viewWindow->textEdit_Surname->setText(model->accessAccount()->getSurname());
        viewWindow->textEdit_city->setText(model->accessAccount()->getCity());
        viewWindow->textEdit_CAP->setText(model->accessAccount()->getCAP());
        viewWindow->textEdit_Address->setText(model->accessAccount()->getAddress());
        viewWindow->textEdit_PhoneNumber->setText(model->accessAccount()->getPhoneNumber());
        viewWindow->textEdit_Mail->setText(model->accessAccount()->getMail());

    }


}

void View::RESET() {

    controller->reset();

}

//-------------------------------------
//SALVATAGGI

void View::accountSave() {

    std::vector<QString> strings;

    strings[0]=viewWindow->textEdit_Name->toPlainText();
    strings[1]=viewWindow->textEdit_Surname->toPlainText();
    strings[2]=viewWindow->textEdit_city->toPlainText();
    strings[3]=viewWindow->textEdit_CAP->toPlainText();
    strings[4]=viewWindow->textEdit_Address->toPlainText();
    strings[5]=viewWindow->textEdit_PhoneNumber->toPlainText();
    strings[6]=viewWindow->textEdit_Mail->toPlainText();


    if(model->isTabAccountLocked()){

        controller->accountSave(strings);

    }else{


    }

}


//--------------------------