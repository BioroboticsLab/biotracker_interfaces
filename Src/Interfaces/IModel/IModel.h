#pragma once

#include <QObject>

#include "memory"
#include <Interfaces/API.h>
class BT_INTERFACES_API IModel : public QObject {
    Q_OBJECT
  public:
    explicit IModel(QObject *parent = 0);
    ~IModel();

  Q_SIGNALS:

    void notifyView();

  public Q_SLOTS:
};
