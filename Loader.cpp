

#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include "Loader.h"
#include "View.h"


bool Loader::isFirstTime() {

    QFile file(DEFAULTPATH);

    QTextStream in(&file);

    if(in.readAll()=="")
        return true;

    file.close();

    return false;

}
