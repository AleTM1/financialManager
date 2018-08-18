//
// Created by alessandro on 07/08/18.
//

#ifndef QTPROVA_MODEL_H
#define QTPROVA_MODEL_H


#include "Subject.h"
#include "Account.h"
#include "Conto.h"
#include "Historical.h"
#include "ErrorLog.h"

class Model : public Subject {

public:

    Model();

    ~Model();

    bool isFirstOpening();

    void createAccount();

    void loadAll();

    void clearAll();

    void saveAccount(std::map<std::string, QString>);

    void saveConto(QString);

    void saveHistorical(Transaction);

    bool doTransaction(Transaction transaction);

    void makeMessageDialogNoButtons(QString ttl, QString txt);

public:

    bool isTabAccountLocked() const;

    void setTabAccountLocked(bool tabAccountLocked);

    AbstractDataStorage* accessDataStorage(std::string) const;

    ErrorLog *getErrorLog() const;

private:

    bool tabAccountLocked;
    Account* account;
    Conto* conto;
    Historical* historical;

    std::vector<AbstractDataStorage*> dataStorages;

    ErrorLog* errorLog = nullptr;

};


#endif //QTPROVA_MODEL_H
