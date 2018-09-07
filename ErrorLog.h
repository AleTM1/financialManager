//
// Created by alessandro on 18/08/18.
//

#ifndef FINANCIALMANAGER_ERRORFORM_H
#define FINANCIALMANAGER_ERRORFORM_H
#include <QtCore/QString>

class ErrorLog {
 public:
  ErrorLog(QString ttl, QString txt) : title(ttl), text(txt), activated(true) {}

  bool isActivated() const {
    return activated;
  }

  void setActivated(bool activated) {
    ErrorLog::activated = activated;
  }

  const QString &getTitle() const {
    return title;
  }

  void setTitle(const QString &title) {
    ErrorLog::title = title;
  }

  const QString &getText() const {
    return text;
  }

  void setText(const QString &text) {
    ErrorLog::text = text;
  }

 protected:
  bool activated;
  QString title;
  QString text;
};
#endif //FINANCIALMANAGER_ERRORFORM_H
