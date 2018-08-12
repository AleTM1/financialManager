//
// Created by alessandro on 07/08/18.
//

#ifndef QTPROVA_MODEL_H
#define QTPROVA_MODEL_H


#include "Subject.h"
#include "Account.h"

class Model : public Subject {

public:

    Model();

    ~Model();

    bool firstOpening();

    void loadAll();

    void loadAccount();

    void loadConto();


    public:

    bool isTabAccountLocked() const;

    void setTabAccountLocked(bool tabAccountLocked);

    const Account* accessAccount() const;

    void clearAll();

private:

    bool tabAccountLocked;
    Account* account;

};


#endif //QTPROVA_MODEL_H
