#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

using namespace std::placeholders;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::submit_all);

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
    view->resizeColumnsToContents();
    ui->centralWidget->layout()->addWidget(view);

    mapper_ = new QDataWidgetMapper(this);
    mapper_->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
    mapper_->setModel(table_);

    Mapping(ui->ip, std::bind(&MainWindow::ip_slot, this, _1));
    Mapping(ui->is_external_start_trigger, std::bind(&MainWindow::start_trigger_slot, this, _1));
    Mapping(ui->scan_rate, std::bind(&MainWindow::scan_rate_slot, this, _1));
    Mapping(ui->trigger_mode, std::bind(&MainWindow::trigger_mode_slot, this, _1));
    Mapping(ui->exposure_time, std::bind(&MainWindow::exposure_time_slot, this, _1));

    mapper_->toFirst();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Mapping(QWidget* widget, const std::function<void(const QVariant&)>& slot)
{
    int table_index = table_->fieldIndex(widget->objectName());
    qDebug() << table_index;
    mapper_->addMapping(widget, table_index);
    connect(table_, &QSqlTableModel::dataChanged,
            [=](const QModelIndex& left, const QModelIndex& right, const QVector<int> role){
                if ((left != right) || (table_index != left.column())) return;
                slot(left.data());
            }
    );
}

void MainWindow::ip_slot(const QVariant& data)
{
    qDebug() << "ip_slot:" << data;
}

void MainWindow::scan_rate_slot(const QVariant& data)
{
    qDebug() << "scan_rate:" << data;
}

void MainWindow::start_trigger_slot(const QVariant &data)
{
    qDebug() << "start_trigger:" << data;
}

void MainWindow::trigger_mode_slot(const QVariant &data)
{
    qDebug() << "trigger_mode:" << data;
}

void MainWindow::exposure_time_slot(const QVariant &data)
{
    qDebug() << "exposure_time:" << data;
}

void MainWindow::submit_all()
{
    mapper_->submit();
}
