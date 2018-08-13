//
// Created by alessandro on 13/08/18.
//

#ifndef FINANCIALMANAGER_ABSTRACTDATASTORAGE_H
#define FINANCIALMANAGER_ABSTRACTDATASTORAGE_H


#include <QtCore/QSettings>
#include <QString>

class AbstractDataStorage{

public:

    virtual void loadData()=0;

    virtual void saveData(std::map<std::string, QString>) = 0;

    virtual void clear(){

        data.clear();
        data.remove(group);
        data.sync();
        loadData();

    }


    virtual ~AbstractDataStorage(){}

protected:

    QSettings data;
    QString group;


};



#endif //FINANCIALMANAGER_ABSTRACTDATASTORAGE_H
