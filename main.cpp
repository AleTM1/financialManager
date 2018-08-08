//ctrl+Maiusc+K

#include <QtWidgets/QApplication>

#include "Model.h"
#include "Controller.h"
#include "View.h"

//#include "main.moc"

int main(int argv, char **args) {

    QApplication app(argv, args);

    auto model = new Model;
    auto controller = new Controller(model);
    View view(controller, model);

    view.show();

    app.exec();

    delete model;
    delete controller;

}
