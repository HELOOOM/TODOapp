#include "task.h"
#include "taskdescription.h"


Task::Task(QString desc,bool fin,QString tag,QDate ddate)
{
    description = desc;
    finished  = fin;
    tag=this->tag;
    duedate=ddate;
}

