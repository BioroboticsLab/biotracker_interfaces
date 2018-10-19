#ifndef IGRAPHICSVIEW_H
#define IGRAPHICSVIEW_H

#include "QGraphicsView"
#include "IView.h"

class BT_INTERFACES_API IViewGraphicsView : public QGraphicsView, public IView
{
    Q_OBJECT
public:
    IViewGraphicsView(QWidget *parent = 0, IController *controller = 0, IModel *model = 0);

    // IView interface
public:
    void setNewModel(IModel *model) override;

protected:
    void connectModelView() override;

public Q_SLOTS:
  virtual void getNotified() = 0;
};

#endif // IGRAPHICSVIEW_H
