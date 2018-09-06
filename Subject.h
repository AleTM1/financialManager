//
// Created by alessandro on 07/08/18.
//

#ifndef QTPROVA_SUBJECT_H
#define QTPROVA_SUBJECT_H

#include <list>
#include "Observer.h"

class Subject {

public:

    virtual void addObserver(Observer* o)
    {

        observers.push_back(o);
    }

    virtual void removeObserver(Observer* o)
    {

        observers.remove(o);
    }

    virtual void notify()
    {

        for (auto o:observers)
            o->update();
    }

    virtual ~Subject() { }

protected:

    std::list<Observer*> observers;

};

#endif //QTPROVA_SUBJECT_H
