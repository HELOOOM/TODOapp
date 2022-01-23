/********************************************************************************
** Form generated from reading UI file 'todoapp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TODOAPP_H
#define UI_TODOAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToDoApp
{
public:
    QAction *action_New;
    QAction *action_Quit;
    QAction *action_Task_Pending;
    QAction *action_Task_finished;
    QAction *actionToday_s_Tasks;
    QAction *actionAll_Tasks;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *todays_task;
    QListWidget *to_be_done;
    QListWidget *finished;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menuOptions;
    QMenu *menu_Help;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *ToDoApp)
    {
        if (ToDoApp->objectName().isEmpty())
            ToDoApp->setObjectName(QString::fromUtf8("ToDoApp"));
        ToDoApp->resize(800, 600);
        action_New = new QAction(ToDoApp);
        action_New->setObjectName(QString::fromUtf8("action_New"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Desktop/ilyas c++/icons/new_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon);
        action_Quit = new QAction(ToDoApp);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Desktop/ilyas c++/icons/quit_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Quit->setIcon(icon1);
        action_Task_Pending = new QAction(ToDoApp);
        action_Task_Pending->setObjectName(QString::fromUtf8("action_Task_Pending"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Downloads/icons8-and-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Task_Pending->setIcon(icon2);
        action_Task_finished = new QAction(ToDoApp);
        action_Task_finished->setObjectName(QString::fromUtf8("action_Task_finished"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Downloads/icons8-t\303\242che-termin\303\251e-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Task_finished->setIcon(icon3);
        actionToday_s_Tasks = new QAction(ToDoApp);
        actionToday_s_Tasks->setObjectName(QString::fromUtf8("actionToday_s_Tasks"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Downloads/icons8-t\303\242che-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionToday_s_Tasks->setIcon(icon4);
        actionAll_Tasks = new QAction(ToDoApp);
        actionAll_Tasks->setObjectName(QString::fromUtf8("actionAll_Tasks"));
        centralwidget = new QWidget(ToDoApp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        todays_task = new QListWidget(centralwidget);
        todays_task->setObjectName(QString::fromUtf8("todays_task"));
        todays_task->setDragEnabled(true);
        todays_task->setDragDropOverwriteMode(true);
        todays_task->setDragDropMode(QAbstractItemView::DragOnly);
        todays_task->setDefaultDropAction(Qt::MoveAction);
        todays_task->setSelectionBehavior(QAbstractItemView::SelectItems);
        todays_task->setSortingEnabled(true);

        horizontalLayout->addWidget(todays_task);

        to_be_done = new QListWidget(centralwidget);
        to_be_done->setObjectName(QString::fromUtf8("to_be_done"));
        to_be_done->setDragEnabled(true);
        to_be_done->setDragDropOverwriteMode(true);
        to_be_done->setDragDropMode(QAbstractItemView::DragOnly);
        to_be_done->setDefaultDropAction(Qt::MoveAction);

        horizontalLayout->addWidget(to_be_done);


        verticalLayout->addLayout(horizontalLayout);

        finished = new QListWidget(centralwidget);
        finished->setObjectName(QString::fromUtf8("finished"));
        finished->setDragEnabled(true);
        finished->setDragDropOverwriteMode(true);
        finished->setDragDropMode(QAbstractItemView::DropOnly);
        finished->setDefaultDropAction(Qt::MoveAction);

        verticalLayout->addWidget(finished);


        verticalLayout_2->addLayout(verticalLayout);

        ToDoApp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ToDoApp);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menu_Help = new QMenu(menubar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        ToDoApp->setMenuBar(menubar);
        statusbar = new QStatusBar(ToDoApp);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ToDoApp->setStatusBar(statusbar);
        toolBar = new QToolBar(ToDoApp);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        ToDoApp->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menubar->addAction(menu_Help->menuAction());
        menu_File->addAction(action_New);
        menu_File->addAction(action_Quit);
        menuOptions->addSeparator();
        menuOptions->addAction(actionToday_s_Tasks);
        menuOptions->addAction(action_Task_Pending);
        menuOptions->addAction(action_Task_finished);
        menuOptions->addAction(actionAll_Tasks);
        toolBar->addAction(action_New);
        toolBar->addAction(action_Quit);
        toolBar->addAction(actionToday_s_Tasks);
        toolBar->addAction(action_Task_Pending);
        toolBar->addAction(action_Task_finished);
        toolBar->addAction(actionAll_Tasks);

        retranslateUi(ToDoApp);
        QObject::connect(action_Quit, SIGNAL(triggered()), ToDoApp, SLOT(close()));

        QMetaObject::connectSlotsByName(ToDoApp);
    } // setupUi

    void retranslateUi(QMainWindow *ToDoApp)
    {
        ToDoApp->setWindowTitle(QCoreApplication::translate("ToDoApp", "ToDoApp", nullptr));
        action_New->setText(QCoreApplication::translate("ToDoApp", "&New", nullptr));
#if QT_CONFIG(shortcut)
        action_New->setShortcut(QCoreApplication::translate("ToDoApp", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Quit->setText(QCoreApplication::translate("ToDoApp", "&Quit", nullptr));
#if QT_CONFIG(shortcut)
        action_Quit->setShortcut(QCoreApplication::translate("ToDoApp", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Task_Pending->setText(QCoreApplication::translate("ToDoApp", "Pending &Tasks", nullptr));
        action_Task_finished->setText(QCoreApplication::translate("ToDoApp", "Finished &Tasks ", nullptr));
        actionToday_s_Tasks->setText(QCoreApplication::translate("ToDoApp", "Today's &Tasks", nullptr));
        actionAll_Tasks->setText(QCoreApplication::translate("ToDoApp", "All &Tasks", nullptr));
        menu_File->setTitle(QCoreApplication::translate("ToDoApp", "&File", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("ToDoApp", "&Options", nullptr));
        menu_Help->setTitle(QCoreApplication::translate("ToDoApp", "&Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("ToDoApp", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToDoApp: public Ui_ToDoApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODOAPP_H
