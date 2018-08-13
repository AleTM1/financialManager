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

    //---------------salvataggi

    void accountSave(std::map<std::string, QString>);

    void ContoSave(std::map<std::string, QString>);

    //-----------------------

private:

    Model* model;

};


#endif //QTPROVA_CONTROLLER_H
