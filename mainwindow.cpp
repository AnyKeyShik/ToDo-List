#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow()
{
    auto widget = new QWidget();
    setCentralWidget(widget);

    table = new QTableWidget(this);
    initializeTable();

    auto vbox = new QVBoxLayout;
    vbox->setMargin(8);
    vbox->addWidget(table);
    vbox->setStretch(0, 0);
    vbox->setStretch(1, 0);
    vbox->setStretch(2, 1);

    widget->setLayout(vbox);

    setWindowTitle("ToDo List QT");
    setMinimumSize(480, 320);
    resize(580, 480);
}

void MainWindow::initializeTable()
{
    table -> setColumnCount(4);
    tableHeader << "Title" << "Description" << "Deadline" << "Creation Data";
    table -> setHorizontalHeaderLabels(tableHeader);
    table -> horizontalHeader()->setStretchLastSection(true);
    table -> verticalHeader() -> setVisible(false);
    table -> setEditTriggers(QAbstractItemView::NoEditTriggers);
    table -> setSelectionBehavior(QAbstractItemView::SelectRows);
    table -> setSelectionMode(QAbstractItemView::MultiSelection);
    table -> setStyleSheet("QTableView {selection-background-color: #E0F7FA; selection-color: #000000;}");

    auto task_name = new Task("Task1");
    auto task_nd = new Task("Task2", "Test description");
    auto task_ndd = new Task("Foo", "Bar", QDate::currentDate().addDays(6));

    std::vector<Task*> tasks;
    tasks.push_back(task_name);
    tasks.push_back(task_nd);
    tasks.push_back(task_ndd);

    updateTable(tasks);
}

void MainWindow::updateTable(std::vector<Task*> data){
    table->clearContents();
    table->setRowCount(static_cast<int>(data.size()));
    unsigned int i;
    for(i = 0; i < data.size(); i++)
    {
        auto qdd = new QTableWidgetItem(data.at(i)->getName());
        qdd->setTextAlignment(Qt::AlignCenter);
        table->setItem(static_cast<int>(i), 0, qdd);
        table->setItem(static_cast<int>(i), 1, new QTableWidgetItem(data.at(i)->getDescription()));
        table->setItem(static_cast<int>(i), 2, new QTableWidgetItem(data.at(i)->getDeadline()));
        table->setItem(static_cast<int>(i), 3, new QTableWidgetItem(data.at(i)->getCreationDate()));
    }
}

MainWindow::~MainWindow() {}
