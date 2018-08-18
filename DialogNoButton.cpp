//
// Created by alessandro on 18/08/18.
//

#include "DialogNoButton.h"

void DialogNoButton::setTitleError(QString stringa) {

    dialogUi->label_titleError->setText("Errore: " + stringa);

}

void DialogNoButton::setTextError(QString stringa) {

    dialogUi->label_text->setText(stringa);

}