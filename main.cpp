//ctrl+Maiusc+K for commit

#include <QtWidgets/QApplication>

#include "Model.h"
#include "Controller.h"
#include "View.h"



int main(int argv, char **args) {

    QApplication app(argv, args);

    auto model = new Model;
    auto controller = new Controller(model);
    View view(controller, model);

    view.show();

    app.exec();




}
