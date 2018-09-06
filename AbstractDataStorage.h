//
// Created by alessandro on 13/08/18.
//

#ifndef FINANCIALMANAGER_ABSTRACTDATASTORAGE_H
#define FINANCIALMANAGER_ABSTRACTDATASTORAGE_H

#include <QtCore/QSettings>
#include <QString>

class AbstractDataStorage {

public:

    virtual void loadData()=0;

    virtual void saveData() = 0;

    virtual void clear()
    {

        data.clear();
        data.remove(groupName);
        data.sync();
        loadData();

    }

    virtual ~AbstractDataStorage() { }

    const QString& getGroupName() const
    {

        return groupName;
    }

protected:

    QSettings data;

    QString groupName;

};

#endif //FINANCIALMANAGER_ABSTRACTDATASTORAGE_H
