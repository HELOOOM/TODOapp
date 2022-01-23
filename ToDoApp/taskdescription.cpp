#include "taskdescription.h"
#include "ui_taskdescription.h"
#include "task.h"
#include "todoapp.h"




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

