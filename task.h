#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDate>

class Task
{
public:
    Task(QString task_name, QString task_description, QDate deadline);
    Task(QString task_name, QString task_description);
    Task(QString tasl_name);

    QString getName();
    QString getDescription();
    QString getCreationDate();
    QString getDeadline();

    bool setName(QString new_name);
    bool setDescription(QString new_description);
    bool setDeadline(QDate new_deadline);

private:
    QString task_name;
    QString task_description;
    QDate date_create;
    QDate deadline;
};

#endif // TASK_H
