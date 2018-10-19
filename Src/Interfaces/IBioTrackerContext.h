#ifndef IBIOTRACKERCONTEXT_H
#define IBIOTRACKERCONTEXT_H

#include <QObject>
#include "QMap"
#include "QString"
#include "Interfaces/ENUMS.h"
#include <Interfaces/API.h>

class IController;
class BT_INTERFACES_API IBioTrackerContext : public QObject
{
    Q_OBJECT
public:
    IBioTrackerContext(QObject *parent = 0);
    ~IBioTrackerContext() {}

    void createApplication();

    IController * requestController(ENUMS::CONTROLLERTYPE ctrtype);

protected:
    virtual void createAppController();
    virtual void connectController();

    void addController(IController * ctr);
protected:
    QMap<ENUMS::CONTROLLERTYPE, IController *> m_ControllersMap;



};

#endif // IBIOTRACKERCONTEXT_H
