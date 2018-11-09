#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("gocator123.sqlite");
    if (!db.open()) {
        qDebug() << "db open fail.";
        return;
    }
    table_ = new QSqlTableModel(this);
    table_->setTable("gocator");
    table_->setEditStrategy(QSqlTableModel::OnFieldChange);
    table_->select();

    QTableView *view = new QTableView;
    view->setModel(table_);
//    view->resizeColumnsToContents();
    ui->centralWidget->layout()->addWidget(view);

    mapper_ = new QDataWidgetMapper(this);
    mapper_->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
    mapper_->setModel(table_);

    Mapping(ui->ip, table_, std::bind(&MainWindow::ip_slot, this));
//    Mapping(ui->is_external_start_trigger, table_);
//    Mapping(ui->scan_rate, table_);
//    Mapping(ui->trigger_mode, table_);
//    Mapping(ui->exposure_time, table_);

//    table_->select();
    mapper_->toFirst();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Mapping(QWidget* widget, QSqlTableModel* table, std::function<void()> slot)
{
    mapper_->addMapping(widget, table->fieldIndex(widget->objectName()));
    connect(ui->pushButton, &QPushButton::clicked, this, slot);
}

void MainWindow::ip_slot()
{
    qDebug() << "hei";
}

void MainWindow::scan_rate_slot()
{

}
