#pragma once

#include <QMainWindow>
#include "Interfaces/IView/IView.h"

class BT_INTERFACES_API IViewMainWindow : public QMainWindow, public IView {
  public:
    IViewMainWindow(QWidget *parent = 0, IController *controller = 0, IModel *model = 0);
    ~IViewMainWindow();

  private:
    void setNewModel(IModel *model);
    void connectModelView();
};
