#ifndef DIALOGERRORNOBUTTONDL3694_H
#define DIALOGERRORNOBUTTONDL3694_H
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
QT_BEGIN_NAMESPACE
class Ui_DialogNoButton {
 public:
  QVBoxLayout *verticalLayout;
  QVBoxLayout *verticalLayout_2;
  QLabel *label_titleError;
  QLabel *label_text;
  QHBoxLayout *horizontalLayout;
  QSpacerItem *horizontalSpacer_2;
  QPushButton *pushButton_closeDialog;
  QSpacerItem *horizontalSpacer;

  void setupUi(QDialog *Dialog) {
    if (Dialog->objectName().isEmpty()) {
      Dialog->setObjectName(QStringLiteral("Message"));
    }
    Dialog->resize(434, 235);
    verticalLayout = new QVBoxLayout(Dialog);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
    label_titleError = new QLabel(Dialog);
    label_titleError->setObjectName(QStringLiteral("label_titleError"));
    QFont font;
    font.setPointSize(18);
    label_titleError->setFont(font);
    label_titleError->setAlignment(Qt::AlignCenter);
    verticalLayout_2->addWidget(label_titleError);
    label_text = new QLabel(Dialog);
    label_text->setObjectName(QStringLiteral("label_text"));
    QFont font1;
    font1.setPointSize(13);
    label_text->setFont(font1);
    label_text->setAlignment(Qt::AlignCenter);
    verticalLayout_2->addWidget(label_text);
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    horizontalLayout->addItem(horizontalSpacer_2);
    pushButton_closeDialog = new QPushButton(Dialog);
    pushButton_closeDialog->setObjectName(QStringLiteral("pushButton_closeDialog"));
    horizontalLayout->addWidget(pushButton_closeDialog);
    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    horizontalLayout->addItem(horizontalSpacer);
    verticalLayout_2->addLayout(horizontalLayout);
    verticalLayout->addLayout(verticalLayout_2);
    QObject::connect(pushButton_closeDialog, SIGNAL(clicked()), Dialog, SLOT(close()));
    retranslateUi(Dialog);
    QMetaObject::connectSlotsByName(Dialog);
  } // setupUi

  void retranslateUi(QDialog *Dialog) {
    Dialog->setWindowTitle(QApplication::translate("Dialog", "Message", Q_NULLPTR));
    label_titleError->setText(QApplication::translate("Dialog", "error", Q_NULLPTR));
    label_text->setText(QApplication::translate("Dialog", "corpo del testo", Q_NULLPTR));
    pushButton_closeDialog->setText(QApplication::translate("Dialog", "Chiudi", Q_NULLPTR));
  } // retranslateUi

};
namespace Ui {
class Dialog : public Ui_DialogNoButton {
};
} // namespace Ui

QT_END_NAMESPACE
#endif // DIALOGERRORNOBUTTONDL3694_H
