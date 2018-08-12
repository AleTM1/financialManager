//
// Created by alessandro on 13/08/18.
//

#ifndef FINANCIALMANAGER_ABSTRACTDATASTORAGE_H
#define FINANCIALMANAGER_ABSTRACTDATASTORAGE_H


#include <QtCore/QSettings>

class AbstractDataStorage{

public:

    virtual void loadData()=0;

    virtual void clear() = 0;

    virtual ~AbstractDataStorage(){}


protected:

    QSettings data;


};



#endif //FINANCIALMANAGER_ABSTRACTDATASTORAGE_H
