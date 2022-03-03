#include "object.h"
#include <QDebug>

Object::Object(const QString& name) : _name(name)
{
}

void Object::addElement(QString key, QVariant v)
{
    _storage[key] = v;
}
