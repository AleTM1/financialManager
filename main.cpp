#include <QtWidgets/QApplication>
#include "Model.h"
#include "Controller.h"
#include "View.h"
#include "Timer.h"

int main(int argv, char** args) {

    QApplication app(argv, args);

    auto model = new Model;
    auto controller = new Controller(model);
    auto view = new View(controller, model);
    auto timer = new Timer(view);

    view->show();

    app.exec();

    delete timer;
    delete view;
    delete controller;
    delete model;

}
