//
// Created by alessandro on 07/08/18.
//

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
