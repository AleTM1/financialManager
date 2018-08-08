//
// Created by alessandro on 08/08/18.
//

#ifndef FINANCIALMANAGER_ACCOUNT_H
#define FINANCIALMANAGER_ACCOUNT_H


#include <QtCore/QString>

class Account {

public:

    const QString &getName() const;

    void setName(const QString &name);

    const QString &getSurname() const;

    void setSurname(const QString &surname);

    const QString &getCity() const;

    void setCity(const QString &city);

    const QString &getCAP() const;

    void setCAP(const QString &CAP);

    const QString &getAddress() const;

    void setAddress(const QString &address);

    const QString &getPhoneNumber() const;

    void setPhoneNumber(const QString &phoneNumber);

    const QString &getMail() const;

    void setMail(const QString &mail);

    const QString &getIBAN() const;

    void generateIBAN();

protected:

    QString name;
    QString surname;
    QString city;
    QString CAP;
    QString address;
    QString phoneNumber;
    QString mail;

    QString IBAN;



};


#endif //FINANCIALMANAGER_ACCOUNT_H
