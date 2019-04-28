#include "task.h"

Task::Task(QString task_name, QString task_description, QDate deadline)
{ 
    this->task_name = task_name;
    this->task_description = task_description;
    this->deadline = deadline;
    this->date_create = QDate::currentDate();
}

Task::Task(QString task_name, QString task_description)
{
    this->task_name = task_name;
    this->task_description = task_description;
    this->deadline = QDate();
    this->date_create = QDate::currentDate();
}

Task::Task(QString task_name)
{
    this->task_name = task_name;
    this->task_description = QString();
    this->deadline = QDate();
    this->date_create = QDate::currentDate();
}

QString Task::getName()
{
    return this->task_name;
}

QString Task::getDescription()
{
    if(!this->task_description.isNull())
    {
        return this->task_description;
    }

    return "";
}

QString Task::getDeadline()
{
    if(!this->deadline.isNull())
    {
        return this->deadline.toString();
    }

    return "NaN";
}

QString Task::getCreationDate()
{
    return this->date_create.toString();
}

bool Task::setName(QString new_name)
{
    if(!new_name.isNull())
    {
        this->task_name = new_name;

        return true;
    }

    return false;
}

bool Task::setDescription(QString new_description)
{
    this->task_description = new_description;

    return true;
}

bool Task::setDeadline(QDate new_deadline)
{
    if(new_deadline < QDate::currentDate() && new_deadline < this->date_create)
    {
        return false;
    }

    this->deadline = new_deadline;

    return true;
}
