//
// Created by alessandro on 25/08/18.
//

#ifndef FINANCIALMANAGER_ENTITY_H
#define FINANCIALMANAGER_ENTITY_H


#include <QtCore/QString>

class Entity {

public:

    virtual ~Entity()=0;

    const QString &getName() const {
        return name;
    }

    void setName(const QString &name) {
        Entity::name = name;
    }

    const QString &getISIN() const {
        return ISIN;
    }

    void setISIN(const QString &ISIN) {
        Entity::ISIN = ISIN;
    }

    void setShareCost(float value){
        shareCost = value;
    }

    float getShareCost(){
        return shareCost;
    }

protected:

    QString name;
    QString ISIN;
    float shareCost;

};


Entity::~Entity() {}

#endif //FINANCIALMANAGER_ENTITY_H
