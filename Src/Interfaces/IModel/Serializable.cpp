#include "Serializable.h"

#include <qvariant.h>
#include <qmetaobject.h>

QDataStream& operator<<(QDataStream& ds, const Serializable& data)
{
    for (int i = 0; i < data.metaObject()->propertyCount(); ++i) {
        if (data.metaObject()->property(i).isStored(&data)) {
            ds << data.metaObject()->property(i).read(&data);
        }
    }
    return ds;
}
QDataStream& operator>>(QDataStream& ds, Serializable& data)
{
    QVariant var;
    for (int i = 0; i < data.metaObject()->propertyCount(); ++i) {
        if (data.metaObject()->property(i).isStored(&data)) {
            ds >> var;
            data.metaObject()->property(i).write(&data, var);
        }
    }
    return ds;
}