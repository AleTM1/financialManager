//
// Created by alessandro on 18/08/18.
//

#ifndef FINANCIALMANAGER_DIALOGNOBUTTON_H
#define FINANCIALMANAGER_DIALOGNOBUTTON_H


#include <QtWidgets/QDialog>
#include "dialogUi.h"

class DialogNoButton : public QDialog {
    Q_OBJECT
public:

    DialogNoButton():dialogUi(new Ui_DialogNoButton){dialogUi->setupUi(this);}

    void setTitleError(QString);
    void setTextError(QString);


private:

    Ui_DialogNoButton* dialogUi;

};


#endif //FINANCIALMANAGER_DIALOGNOBUTTON_H
