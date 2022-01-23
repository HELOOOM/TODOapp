###### Top
[The End](#the-end)

# ToDo Application using containers

## **BY** : 
- [x] **Benzemroun Badr**
- [x] **Lakhmiri Mohammed Elias**
- [x] **Sakassa Rachid**




## Introduction
### **TODO** List are the lists that we generally use to maintain our day to day tasks or list of everything that we have to do. It is helpful in planning our daily schedules. We can add more tasks any time and delete a task which is completed. The four major tasks that we can perform in a TODO list are:

1. Add tasks
2. Update tasks
3. Read tasks
4. Delete tasks

## TodoMVC is an immensely valuable attempt at a difficult problem - providing a structured way of comparing JS libraries and frameworks. TodoMVC is a lone data point in a sea of conjecture and opinion.

## First let's describe our application
### In our Task Manager application we have:
1. A menu bar containing : "File , Options , Help"
   - file menu containing : "New , Exit"
     - **_New_** is an action which can add a new task to our application
     - **_Exit_** is an action which **save** the contents befor leaving the application
   - options menu containing : "Delete, show all, show pending task, show finished task, show today task"
     - **_Delete task_** is an action which can delete a selected task
     - **_Show all_** is an action which show pending,today and finished task
     - **_Show pending_** is an action which show pending task
     - **_Show finished_** is an action which show finished task
     - **_Show today task_** is an action which show today task
   - Help menu containing : "About , About Qt"
2. A Tool bar containing actions like : "new task, show finished, show pending, delete, exit"
3. A List view; in our application we have tree each one display a specific type of tasks
   
# our application look like this:
![image](https://user-images.githubusercontent.com/53974876/150686344-145503b7-91e5-48f7-8154-ed50ce460d23.png)

- ### presing new file in the application a Qdialoge will pop out

![image](https://user-images.githubusercontent.com/53974876/150686422-eb3b67d5-97e3-4525-814c-a78f1e8d96e7.png)

## this QDialog is containing 
1. A description for your task 
2. A check box for finished tasks
3. tags 
4. date for the task (for today or for a specifique date)
5. two push buttons (ok and cancel)



- ## let's make (Task1, TASK2 and TASK3) with our application, after creating each one now we can see the tasks in the appropriate QlistWidget

![image](https://user-images.githubusercontent.com/53974876/150686523-68016832-c33b-4ab7-8dea-4c4101ef2afe.png)

- ### To save and exit the application press exit icon in the tool bar then press ok

![image](https://user-images.githubusercontent.com/53974876/150686736-130ed12f-3771-44b1-b7ee-391156585658.png)

- ### if you want to check your saves go to the `build-ToDoApp-Desktop_Qt_5_15_0_MinGW_64_bit-Debug` folder

![image](https://user-images.githubusercontent.com/53974876/150686785-a6b8f9d8-7e98-40a4-bffb-f2fed8913b17.png)
    
# **To result with such a functional application you have to go through multiple functions, slots, actions and methods (But don't worry we will explain the functionality and role of each part of our code)** 

## The titles

[TaskDescription.h](#taskdescriptionh)

[TaskDescription.cpp](#taskdescriptioncpp)

[ToDoApp.h](#todoapph)

[ToDoApp.cpp](#todoappcpp)

 - ## First we create two **UI** **( task.ui , taskmanager.ui )**

![image](https://user-images.githubusercontent.com/53974876/150687835-a702cb91-9e0a-4133-9b49-fd67cad8a409.png)![image](https://user-images.githubusercontent.com/53974876/150687806-1f1919bd-369a-45a6-9e2b-71b96911f54e.png)

- ## Now let's see the (Header) TaskDescription

## TaskDescription.h
- ### our class task will inherit from QDialog

```c++
#ifndef TASKDESCRIPTION_H
#define TASKDESCRIPTION_H
#include <QDialog>
#include "task.h"
#include <QListWidgetItem>
namespace Ui {
class TaskDescription;
}
class TaskDescription : public QDialog
{
    Q_OBJECT

public:
    TaskDescription(QWidget *parent = nullptr);
    ~TaskDescription();
    Ui::TaskDescription *ui;
    bool logic=false;
private slots:
    void on_buttonBox_accepted();

private:

   // Ui::TaskDescription *ui;
};
```

 ## TaskDescription.cpp

- ### First we setup our UI then the implementation for the slots already declared in [TaskDescription.h](#taskdescriptionh)
```c++
TaskDescription::TaskDescription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskDescription)
{
    ui->setupUi(this);

}
TaskDescription::~TaskDescription()
{
    delete ui;

}
void TaskDescription::on_buttonBox_accepted()
{

    logic=true;
    close();
}
```
- ### Moving to ToDoApp and starting with `taskmanager.h`

## ToDoApp.h

- ###  first our class ToDoApp will inherit from QMainWindow

```c++
#ifndef TODOAPP_H
#define TODOAPP_H
#include <QMainWindow>
#include <QHBoxLayout>
#include "taskdescription.h"
#include <QFile>
#include <QLayout>
QT_BEGIN_NAMESPACE
namespace Ui { class ToDoApp; }
QT_END_NAMESPACE

class ToDoApp : public QMainWindow
{
    Q_OBJECT

public:
    ToDoApp(QWidget *parent = nullptr);
    ~ToDoApp();
    QFile  lyouma{"item_based Today tasks.txt"};
    QFile salaw{"item_based Finished tasks.txt"};
    QFile apres{"item_based Pending tasks.txt"};

    QStringList TT_list ;
    QStringList PT_list ;
    QStringList FT_list ;

```
- ### Two void functions saveContent and loadContent 

```c++
void saveContent(QFile *filename) const;
void loadContent(QFile *filename);
```

 - ### Here we have all the private slots for our actions
 ```c++
private slots:
    void on_action_New_triggered();
    void on_action_Task_Pending_triggered();
    void on_action_Task_finished_triggered();
    void on_actionToday_s_Tasks_triggered();
    void on_actionAll_Tasks_triggered();
    void closeEvent (QCloseEvent *event);
    void on_action_Quit_triggered();

private:
    Ui::ToDoApp *ui;
};
#endif // TODOAPP_H
 ```   
    
 - ### Now we will see the implementation of eache slot and function   
    
 ## ToDoApp.cpp
 - ### _includes_
 ```c++
#include "todoapp.h"
#include "ui_todoapp.h"
#include "ui_taskdescription.h"
#include "taskdescription.h"
#include <QLayout>
#include <QFileSystemModel>
#include <QPixmap>
#include <QTextStream>
#include <QMessageBox>
#include <QCloseEvent>
#include <QStandardItem>
 ```
 
 - ### Starting with the constructor and Destructor
 ```c++
ToDoApp::ToDoApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ToDoApp)
{
    ui->setupUi(this);
    QFile  lyouma{"item_based Today tasks.txt"};
    QFile salaw{"item_based Finished tasks.txt"};
    QFile apres{"item_based Pending tasks.txt"};
    loadContent(&salaw);
    loadContent(&lyouma);
    loadContent(&apres);
}
ToDoApp::~ToDoApp()
{
    delete ui;
}
 ```
- ### The implementation of the `on_action_New_triggered()` slot
here we will use the bool `logic` already declared in `TaskDescription` if the **Ok** button in `TaskDescription.ui` is clicked `logic=true` if **Cancel** is clicked `logic=false`
after checking the logic if is it true or not now we should check the type of the task (finished,today or pending) . We passed through this conditions to store each task in their appropriate listView  


```c++
void ToDoApp::on_action_New_triggered()
{
    TaskDescription T;
    T.ui->date->setDate(QDate::currentDate());
    T.exec();
    if(T.logic){

   if(T.ui->fincheck->isChecked()){


       FT_list.append(T.ui->description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
       QString path{":/new/prefix1/icone2/finished"};
       QPixmap icon(path);
       ui->finished->addItem(new QListWidgetItem(icon,T.ui->description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText()));
           }
   else if(T. ui->date->date().toString("ddd MMMM d yyyy")==QDate::currentDate().toString("ddd MMMM d yyyy")){

       TT_list.append(T.ui->description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
       QString path{":/new/prefix1/icone2/today"};
       QPixmap icon(path);
       ui->todays_task->addItem(new QListWidgetItem(icon,T.ui->description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText()));
  }
   else{
      PT_list.append(T.ui->description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());

      QString path{":/new/prefix1/icone2/pending"};
      QPixmap icon(path);
      ui->to_be_done->addItem(new QListWidgetItem(icon,T.ui->description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText()));
    }
T.close();
      }
}
```
    
- ### load content 
this function load the content of each listview using `QStringList` (TT_list,PT_list,FT_list)

```c++
void ToDoApp::loadContent(QFile *filename){
    if (filename->open(QIODevice::ReadOnly)) {

        if(filename->fileName()==salaw.fileName()){
            QTextStream in(filename);
            while (!in.atEnd()) {
                QString line = in.readLine();
                FT_list.append(line);
                 QString path{":/new/prefix1/icone2/finished"};
                  QPixmap icon(path);
                  ui->finished->addItem(new QListWidgetItem(icon,line));
           }
       }
        if(filename->fileName()==lyouma.fileName()){
            QTextStream in(filename);
            while (!in.atEnd()) {
                QString line = in.readLine();
                TT_list.append(line);
                 QString path{":/new/prefix1/icone2/today"};
                  QPixmap icon(path);
                  ui->todays_task->addItem(new QListWidgetItem(icon,line));
            }
        }
        if(filename->fileName()==apres.fileName()){
            QTextStream in(filename);
            while (!in.atEnd()) {
                QString line = in.readLine();
                PT_list.append(line);
                 QString path{":/new/prefix1/icone2/pending"};
                  QPixmap icon(path);
                  ui->to_be_done->addItem( new QListWidgetItem(icon,line));
               }
          }
    }
}
```
- ### Saves
#### We will implement saveContent which saves the content of each QListWidget
```c++
void ToDoApp::saveContent(QFile *filename) const
{
    //Openign the file
    if(filename->open(QIODevice::WriteOnly))  //Opening the file in writing mode
    {
        //Initiating a stream using the file
        QTextStream out(filename);
        if(filename==&lyouma){

        for ( int i=0; i < TT_list.size(); ++i )
                        out << TT_list.at(i) << "\n";
        }
        else if(filename==&salaw){

            for ( int i=0; i < FT_list.size(); ++i )
                            out <<FT_list.at(i) << "\n";
        }
        else if(filename==&apres){
            for ( int i=0; i <PT_list.size(); ++i )
                            out << PT_list.at(i) << "\n";
        }
    }
    filename->close();
}
```

- ### Close event
```c++
void ToDoApp::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Task MAnager",
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        on_action_Quit_triggered();
        event->accept();
    }
}
```
- ### we have three slots called `on_action_Task_Pending_triggered , on_action_Task_finished_triggered , on_actionToday_s_Tasks_triggered , on_actionAll_Tasks_triggered`

```c++
void ToDoApp::on_action_Task_Pending_triggered()
{
     ui->to_be_done->show();
     ui->todays_task->hide();
      ui->finished->hide();
}
void ToDoApp::on_action_Task_finished_triggered()
{
     ui->todays_task->hide();
     ui->to_be_done->hide();
     ui->finished->show();
}
void ToDoApp::on_actionToday_s_Tasks_triggered()
{
     ui->finished->hide();
     ui->to_be_done->hide();
     ui->todays_task->show();
}
void ToDoApp::on_actionAll_Tasks_triggered()
{
     ui->finished->show();
     ui->to_be_done->show();
     ui->todays_task->show();
}
```
- ### Finally we have the `on_action_Quit_triggered()` slot :

```c++
void ToDoApp::on_action_Quit_triggered()
{
        saveContent(&lyouma);
        saveContent(&salaw);
        saveContent(&apres);
        QMessageBox::information(this,"DONE","saveeeed & exited");
         qApp->exit();
}
```
    
 [Top](#top) 
 
 ###### The End


