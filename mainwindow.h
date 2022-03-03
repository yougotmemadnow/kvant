#pragma once

#include <QMainWindow>
#include <unordered_map>
#include <object.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const std::map<QString, std::vector<std::pair<QString, QVariant>>> &params, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    std::unordered_map<QString, Object> _storage;
};
