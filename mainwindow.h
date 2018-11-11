#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include <QTableView>
#include <QModelIndex>
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
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
    void submit_all();
private:
    Ui::MainWindow *ui;
    QSqlTableModel *table_;
    QDataWidgetMapper *mapper_;

    void Mapping(QWidget* widget,
                 const std::function<void (const QVariant &)> &slot);
};

#endif // MAINWINDOW_H
