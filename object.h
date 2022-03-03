#pragma once

#include <QString>
#include <QVariant>
#include <unordered_map>

class Object
{
public:
    explicit Object(const QString& name);

    void addElement(QString key, QVariant v);

private:
    const QString _name;
    std::unordered_map<QString, QVariant> _storage;
};

