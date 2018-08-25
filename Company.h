//
// Created by alessandro on 25/08/18.
//

#ifndef FINANCIALMANAGER_COMPANY_H
#define FINANCIALMANAGER_COMPANY_H


#include "Entity.h"

class Company : public Entity {

public:

    Company(float coupon, QString nam, QString isin, float cost):montlyCoupon(coupon), Entity(nam, isin, cost){}

    float getMontlyCoupon() const;

    void setMontlyCoupon(float coupon);

protected:

    float montlyCoupon;

};


#endif //FINANCIALMANAGER_COMPANY_H
