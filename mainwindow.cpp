#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::submitAll);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddMappingToDb(QMap<QWidget *, _SLOT_type>& container)
{
    container.insert(ui->ip, _SLOT(this, &MainWindow::ip_slot));
    container.insert(ui->scan_rate, _SLOT(this, &MainWindow::scan_rate_slot));
    container.insert(ui->is_external_start_trigger, _SLOT(this, &MainWindow::start_trigger_slot));
    container.insert(ui->trigger_mode, _SLOT(this, &MainWindow::trigger_mode_slot));
    container.insert(ui->exposure_time, _SLOT(this, &MainWindow::exposure_time_slot));
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

void MainWindow::submitAll()
{
    setModelData(ui->ip, "field test");
}
