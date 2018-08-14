//
// Created by alessandro on 14/08/18.
//

#ifndef FINANCIALMANAGER_QSLIDERREADONLY_H
#define FINANCIALMANAGER_QSLIDERREADONLY_H


class QSliderReadOnly : public QSlider {
Q_OBJECT

public:

    QSliderReadOnly (QWidget *parent = nullptr):QSlider(parent){}

protected:
    void keyPressEvent(QKeyEvent *) {}
    void keyReleaseEvent(QKeyEvent *) {}
    QWidget *keyboardGrabber(){}
    void mouseMoveEvent(QMouseEvent *event){}
    void mousePressEvent(QMouseEvent *event){}
    void mouseReleaseEvent(QMouseEvent *event){}
    void sliderPressed() {}

};


#endif //FINANCIALMANAGER_QSLIDERREADONLY_H
