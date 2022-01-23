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


void ToDoApp::on_action_Quit_triggered()
{
    saveContent(&lyouma);
        saveContent(&salaw);
        saveContent(&apres);
         QMessageBox::information(this,"DONE","saveeeed & exited");
         qApp->exit();
}

