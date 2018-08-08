//
// Created by alessandro on 07/08/18.
//


#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include "View.h"

View::View(Controller *c, Model *m):controller(c), model(m), viewWindow(new Ui_MainWindow) {

    viewWindow->setupUi(this);
    model->addObserver(this);
    update();

}

View::~View() {

    model->removeObserver(this);

    delete viewWindow;

}


void View::update() {


}

bool View::isFirstTime() {

    QFile file(DEFAULTPATH);

    QTextStream in(&file);

    if(in.readAll()=="")
        return true;

    file.close();

    return false;

}
