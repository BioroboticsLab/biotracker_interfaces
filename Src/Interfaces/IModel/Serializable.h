#pragma once
#include <vector>
#include <algorithm>
#include <qobject.h>
#include <QList>
#include <QObject>
#include "IModel.h"

class BT_INTERFACES_API Serializable : public IModel
{
    Q_OBJECT
};

QDataStream& operator<<(QDataStream& out, const Serializable& data);
QDataStream& operator>>(QDataStream& in, Serializable& data);
