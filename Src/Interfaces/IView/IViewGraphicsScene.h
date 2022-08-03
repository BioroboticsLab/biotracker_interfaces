#pragma once

#include "QGraphicsScene"
#include "IView.h"

class BT_INTERFACES_API IViewGraphicsScene : public QGraphicsScene,
                                             public IView
{
    Q_OBJECT
public:
    IViewGraphicsScene(QObject*     parent     = 0,
                       IController* controller = 0,
                       IModel*      model      = 0);

    // IView interface
public:
    virtual void setNewModel(IModel* model) override;

protected:
    virtual void connectModelView() override;

public Q_SLOTS:
    virtual void getNotified() = 0;
};
