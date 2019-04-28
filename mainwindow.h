#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "task.h"

#include <QMainWindow>
#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QCheckBox>

#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow();

private:
    void initializeTable();
    void updateTable(std::vector<Task*> data);

    QTableWidget *table;
    QStringList tableHeader;
};

#endif // MAINWINDOW_H
