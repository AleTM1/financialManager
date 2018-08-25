//
// Created by alessandro on 25/08/18.
//

#ifndef FINANCIALMANAGER_ENTITY_H
#define FINANCIALMANAGER_ENTITY_H


#include <QtCore/QString>
#include <ctime>

class Entity {

public:

    Entity(QString nam, QString isin, float cost):name(nam), ISIN(isin), shareCost(cost){
        srand(time(0));
    }

    virtual ~Entity(){}

    void changeGenerator() {

        shareCost= shareCost * (((rand()%200-100)/100.0)+100.0)/100.0 ;

    }


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


#endif //FINANCIALMANAGER_ENTITY_H
