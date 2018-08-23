
#include <QtWidgets/QApplication>
#include "Model.h"
#include "Controller.h"
#include "View.h"


int main(int argv, char **args) {

    QApplication app(argv, args);

    auto model = new Model;
    auto controller = new Controller(model);
    auto view = new View(controller, model);

    view->show();

    app.exec();

    delete view;
    delete controller;
    delete model;

}
