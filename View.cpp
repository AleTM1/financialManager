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

    viewWindow->textEdit_Name->setText(model->accessAccount()->getName());
    viewWindow->textEdit_Surname->setText(model->accessAccount()->getSurname());
    viewWindow->textEdit_city->setText(model->accessAccount()->getCity());
    viewWindow->textEdit_CAP->setText(model->accessAccount()->getCAP());
    viewWindow->textEdit_Address->setText(model->accessAccount()->getAddress());
    viewWindow->textEdit_PhoneNumber->setText(model->accessAccount()->getPhoneNumber());
    viewWindow->textEdit_Mail->setText(model->accessAccount()->getMail());




}

