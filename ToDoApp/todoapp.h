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

void saveContent(QFile *filename) const;
void loadContent(QFile *filename);
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
