//
// Created by alessandro on 18/08/18.
//

#include "DialogNoButton.h"


DialogNoButton::DialogNoButton(QString ttl, QString txt):dialogUi(new Ui_DialogNoButton){

    dialogUi->setupUi(this);
    setTitleError(ttl);
    setTextError(txt);

}

void DialogNoButton::setTitleError(QString stringa) {

    dialogUi->label_titleError->setText("Evento: " + stringa);

}

void DialogNoButton::setTextError(QString stringa) {

    dialogUi->label_text->setText(stringa);

}

