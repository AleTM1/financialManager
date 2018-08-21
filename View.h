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
    void showSearchOptions();
    void contoTitleSave();
    void radioButtonTransactionClicked();
    void doTransaction();
    void searchHistorical();
    void searchDateChanged();

    //----controlli---
    void lineIBANEdited(const QString &);
    void lineCAPEdited(const QString &);
    void linePhoneNumber(const QString &);
    void codiceFiscaleEdited(const QString &);
    void onlyLetters(const QString &);

private:

    void clearLayout(QLayout *layout);
    QString onlySelectedCharacters(QString& stringa, const QString& allowedCharacters );

private:

    Controller* controller;
    Model* model;
    Ui_MainWindow* viewWindow;

    DialogNoButton* dialogNoButton;



};


#endif //QTPROVA_VIEW_H
