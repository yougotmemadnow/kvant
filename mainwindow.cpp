#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <map>
#include <unordered_set>
#include <vector>
#include <QDebug>

MainWindow::MainWindow(const std::map<QString, std::vector<std::pair<QString, QVariant>> > &params, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->tableWidget, QTableWidget::itemChanged, [this] (QTableWidgetItem *item)
    {
        auto vHeader = ui->tableWidget->verticalHeaderItem(item->row());
        if (vHeader)
        {
            auto it =_storage.find(vHeader->text());
            if (it != _storage.end())
            {
                auto hHeader = ui->tableWidget->horizontalHeaderItem(item->column());
                if (hHeader)
                {
                    bool ok = true;
                    const auto dValue = item->text().toDouble(&ok);
                    if (ok)
                    {
                        it->second.addElement(hHeader->text(), dValue);
                    }
                    else if (item->text().toLower() == "true" || item->text().toLower() == "false")
                    {
                        it->second.addElement(hHeader->text(), item->text().toLower() == "true" ? true : false);
                    }
                    else
                    {
                        it->second.addElement(hHeader->text(), item->text());
                    }
                }
            }
        }
    });

    ///

    ui->tableWidget->setRowCount(params.size());

    auto iter = params.begin();

    std::unordered_set<QString> keys;

    for (size_t i = 0; i < params.size(); ++i)
    {
        ui->tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(iter->first));
        _storage.emplace(iter->first, iter->first);
        auto&& v = (iter++)->second;
        for (auto&& pair : v)
        {
            auto it = keys.insert(pair.first);
            if (it.second)
            {
                ui->tableWidget->insertColumn(ui->tableWidget->columnCount());
                ui->tableWidget->setHorizontalHeaderItem(ui->tableWidget->columnCount() - 1, new QTableWidgetItem(pair.first));
                ui->tableWidget->setItem(i, ui->tableWidget->columnCount() - 1, new QTableWidgetItem(pair.second.toString()));
                ui->tableWidget->item(i, ui->tableWidget->columnCount() - 1)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

