#pragma once

#include "Interfaces/IView/IView.h"
#include <QOpenGLWidget>
#include <QOpenGLTexture>
#include <QOpenGLFunctions>

class BT_INTERFACES_API IViewOpenGLWidget : public QOpenGLWidget,
                                            protected QOpenGLFunctions,
                                            public IView
{
public:
    IViewOpenGLWidget(QWidget*     parent     = 0,
                      IController* controller = 0,
                      IModel*      model      = 0);
    ~IViewOpenGLWidget();

    void setNewModel(IModel* model);

public Q_SLOTS:
    virtual void getNotified() = 0;

protected:
    void connectModelView();
    void initializeGL() override;
};
