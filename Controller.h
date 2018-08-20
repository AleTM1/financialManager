//
// Created by alessandro on 07/08/18.
//

#ifndef QTPROVA_CONTROLLER_H
#define QTPROVA_CONTROLLER_H


#include "Model.h"

class Controller {

public:

    explicit Controller(Model* m) : model(m) {}

    void openingApp();

    void reset();

    void doTransaction(bool, std::map<std::string, QString>, QDate );

    void changeHistoricalOrder(bool);

    //---------------salvataggi

    void accountSave(std::map<std::string, QString>);

    void contoSave(QString);

    //-----------------------

private:

    Model* model;

};


#endif //QTPROVA_CONTROLLER_H
