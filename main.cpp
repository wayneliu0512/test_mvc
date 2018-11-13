#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "testdb");
    db.setDatabaseName("gocator123.sqlite");

    MainWindow w;
    w.AttachToDatabase("testdb", "gocator");
    w.show();

    return a.exec();
}
