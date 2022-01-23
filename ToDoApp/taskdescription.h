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

#endif // TASKDESCRIPTION_H
