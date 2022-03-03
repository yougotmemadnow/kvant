#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w({{"obj1", {{"key1", 0.123}, {"key2", false}, {"key3", "str"}}}, {"obj2", {{"key3", {}}, {"key4", 123.3}, {"key5", true}, {"key6", false}}}});

    w.show();

    return a.exec();
}
