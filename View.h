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
#include "DialogNoButton.h"


class View : public QMainWindow, public Observer {
    Q_OBJECT
public:

    View(Controller *c, Model *m);

    virtual ~View();

    virtual void update() override;




private slots:

    void closeApp();
    void RESET();
    void accountSave();
    void showTitleEdit();
    void contoTitleSave();
    void radioButtonClicked();
    void doTransaction();
    void lineIBANEdited(const QString &);
    void lineNameEdited(const QString &);

private:

    Controller* controller;
    Model* model;
    Ui_MainWindow* viewWindow;

    DialogNoButton* dialogNoButton;

    void clearLayout(QLayout *layout);

};


#endif //QTPROVA_VIEW_H
