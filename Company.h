//
// Created by alessandro on 25/08/18.
//

#ifndef FINANCIALMANAGER_ENTITY_H
#define FINANCIALMANAGER_ENTITY_H
#include <QtCore/QString>
#include <ctime>

class Company {
 public:
  Company(float coupon, QString nam, QString isin, float cost)
      : montlyCoupon(coupon), name(nam), ISIN(isin), shareCost(cost) {
    srand(time(0));
  }

  virtual ~Company() {}

  void changeShareCostGenerator() {
    shareCost += shareCost*((rand()%200 - 100)/100.0)/100.0;
  }

  const QString &getName() const {
    return name;
  }

  void setName(const QString &name) {
    Company::name = name;
  }

  const QString &getISIN() const {
    return ISIN;
  }

  void setISIN(const QString &ISIN) {
    Company::ISIN = ISIN;
  }

  void setShareCost(float value) {
    shareCost = value;
  }

  float getShareCost() {
    return shareCost;
  }

  float getMontlyCoupon() const {
    return montlyCoupon;
  }

  void setMontlyCoupon(float montlyCoupon) {
    Company::montlyCoupon = montlyCoupon;
  }

 protected:
  QString name;
  QString ISIN;
  float shareCost;
  float montlyCoupon;
};
#endif //FINANCIALMANAGER_ENTITY_H
