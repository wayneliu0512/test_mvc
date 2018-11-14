#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include <QTableView>
#include <QModelIndex>
#include <QVector>
#include <g4_core.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public G4Object
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void ip_slot(const QVariant &data);
    void scan_rate_slot(const QVariant& data);
    void start_trigger_slot(const QVariant& data);
    void trigger_mode_slot(const QVariant& data);
    void exposure_time_slot(const QVariant& data);
    void submitAll();
protected:
    void AddMappingToDb(QMap<QWidget*, _SLOT_type>& container) override;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
