#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include <QTableView>

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
    void ip_slot();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *table_;
    QDataWidgetMapper *mapper_;

    void scan_rate_slot();

    void Mapping(QWidget* widget, QSqlTableModel* table, std::function<void()> slot);
};

#endif // MAINWINDOW_H
