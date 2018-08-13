//
// Created by alessandro on 07/08/18.
//

#ifndef QTPROVA_MODEL_H
#define QTPROVA_MODEL_H


#include "Subject.h"
#include "Account.h"
#include "Conto.h"

class Model : public Subject {

public:

    Model();

    ~Model();

    bool firstOpening();

    void loadAll();

    void loadAccount();

    void loadConto();

    void clearAll();

    void save(std::string, std::map<std::string, QString>);

public:

    bool isTabAccountLocked() const;

    void setTabAccountLocked(bool tabAccountLocked);

    Account* accessAccount() const;



private:

    bool tabAccountLocked;
    Account* account;
    Conto* conto;

    std::vector<AbstractDataStorage*> dataStorages;

};


#endif //QTPROVA_MODEL_H
