//
// Created by alessandro on 07/08/18.
//

#ifndef QTPROVA_CONTROLLER_H
#define QTPROVA_CONTROLLER_H


#include "Model.h"

class Controller {
public:
    explicit Controller(Model* m) : model(m) {}


private:
    Model* model;

};


#endif //QTPROVA_CONTROLLER_H
