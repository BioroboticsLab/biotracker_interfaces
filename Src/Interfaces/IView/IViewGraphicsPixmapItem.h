#pragma once

#include "IView.h"
#include "QObject"
#include "QGraphicsPixmapItem"

class BT_INTERFACES_API IViewGraphicsPixmapItem : public QObject, public QGraphicsPixmapItem, public IView
{
    Q_OBJECT
public:
    IViewGraphicsPixmapItem(QObject *parent = 0, IController *controller = 0, IModel *model = 0);

    // IView interface
public:
    void setNewModel(IModel *model) override;

public Q_SLOTS:
  virtual void getNotified() = 0;
};
