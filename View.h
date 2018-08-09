//
// Created by alessandro on 07/08/18.
//


#ifndef QTPROVA_VIEW_H
#define QTPROVA_VIEW_H


#include <QtWidgets/QMainWindow>
#include "Observer.h"
#include "Controller.h"
#include "Model.h"
#include "ViewWindow.h"


class View : public QMainWindow, public Observer {
    Q_OBJECT
public:

    View(Controller *c, Model *m);

    virtual ~View();

    virtual void update() override ;



private slots:



private:

    Controller* controller;
    Model* model;
    Ui_MainWindow* viewWindow;



};


#endif //QTPROVA_VIEW_H
