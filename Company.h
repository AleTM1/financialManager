//
// Created by alessandro on 25/08/18.
//

#ifndef FINANCIALMANAGER_COMPANY_H
#define FINANCIALMANAGER_COMPANY_H


#include "Entity.h"

class Company : public Entity {

public:

    float getCoupon() const;

    void setCoupon(float coupon);

protected:

    float coupon;

};


#endif //FINANCIALMANAGER_COMPANY_H
