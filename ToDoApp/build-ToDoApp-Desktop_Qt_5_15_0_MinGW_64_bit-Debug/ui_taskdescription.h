/********************************************************************************
** Form generated from reading UI file 'taskdescription.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKDESCRIPTION_H
#define UI_TASKDESCRIPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TaskDescription
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TaskDescription)
    {
        if (TaskDescription->objectName().isEmpty())
            TaskDescription->setObjectName(QString::fromUtf8("TaskDescription"));
        TaskDescription->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(TaskDescription);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(TaskDescription);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(TaskDescription);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        checkBox = new QCheckBox(TaskDescription);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(TaskDescription);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox = new QComboBox(TaskDescription);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(TaskDescription);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        dateEdit = new QDateEdit(TaskDescription);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        horizontalLayout_3->addWidget(dateEdit);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(TaskDescription);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(TaskDescription);
        QObject::connect(buttonBox, SIGNAL(accepted()), TaskDescription, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TaskDescription, SLOT(reject()));

        QMetaObject::connectSlotsByName(TaskDescription);
    } // setupUi

    void retranslateUi(QDialog *TaskDescription)
    {
        TaskDescription->setWindowTitle(QCoreApplication::translate("TaskDescription", "Add your task", nullptr));
        label->setText(QCoreApplication::translate("TaskDescription", "Description", nullptr));
        checkBox->setText(QCoreApplication::translate("TaskDescription", "Finished", nullptr));
        label_2->setText(QCoreApplication::translate("TaskDescription", "Tag", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("TaskDescription", "Work", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("TaskDescription", "Life", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("TaskDescription", "Others", nullptr));

        label_3->setText(QCoreApplication::translate("TaskDescription", "Due Date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskDescription: public Ui_TaskDescription {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKDESCRIPTION_H
