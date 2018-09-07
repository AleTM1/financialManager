//
// Created by alessandro on 28/08/18.
//

#ifndef FINANCIALMANAGER_TIMER_H
#define FINANCIALMANAGER_TIMER_H
#include <QWidget>
#include <QtWidgets>
#include "View.h"
class Timer : public QWidget {
 Q_OBJECT
 public:
  Timer(View *view, QWidget *parent = 0);
 private slots:
  void refresh();
 protected:
  View *view;
};
#endif //FINANCIALMANAGER_TIMER_H
