#pragma once

#include "Interfaces/IModel/IModel.h"
#include "Interfaces/ENUMS.h"
#include <Interfaces/API.h>
class IController;
class BT_INTERFACES_API IView
{

public:
    IView(IController* controller = 0, IModel* model = 0);
    virtual ~IView() = 0;

    virtual void setNewModel(IModel* model) = 0;
    void         setPermission(std::pair<ENUMS::COREPERMISSIONS, bool>);

protected:
    virtual void       connectModelView() = 0;
    void               setModel(IModel* model);
    IController*       getController();
    const IController* getController() const;
    IModel*            getModel();
    const IModel*      getModel() const;

private:
    IController* mController;
    IModel*      mModel;
};
