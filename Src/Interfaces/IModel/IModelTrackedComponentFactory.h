#pragma once

#include "IModel.h"
#include "IModelTrackedComponent.h"

class BT_INTERFACES_API IModelTrackedComponentFactory : public IModel
{
    Q_OBJECT

public:
    IModelTrackedComponentFactory();
    virtual ~IModelTrackedComponentFactory() = 0;

    IModelTrackedComponent* getNewTrackedElement(QString name);
    IModelTrackedComponent* getNewTrackedObject(QString name);
    IModelTrackedComponent* getNewTrackedTrajectory(QString name);
    virtual QList<QString>  getElementTypes() = 0;

protected:
    virtual IModelTrackedComponent* createTrackedElement(QString name)    = 0;
    virtual IModelTrackedComponent* createTrackedObject(QString name)     = 0;
    virtual IModelTrackedComponent* createTrackedTrajectory(QString name) = 0;
};
