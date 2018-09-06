//
// Created by alessandro on 07/08/18.
//

#ifndef QTPROVA_OBSERVER_H
#define QTPROVA_OBSERVER_H

class Observer {

public:

    virtual void update() =0;

    virtual ~Observer() { }

};

#endif //QTPROVA_OBSERVER_H
