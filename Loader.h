//
// Created by alessandro on 09/08/18.
//

#ifndef FINANCIALMANAGER_LOADER_H
#define FINANCIALMANAGER_LOADER_H


#include <fstream>
#include <iostream>
#include <QtCore/QSettings>


class Loader {

public:

    Loader();


protected:

    bool firstTime=true;
    QSettings data;

};


#endif //FINANCIALMANAGER_LOADER_H
