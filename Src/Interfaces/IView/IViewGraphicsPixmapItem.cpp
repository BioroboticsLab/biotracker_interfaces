#include "IViewGraphicsPixmapItem.h"

IViewGraphicsPixmapItem::IViewGraphicsPixmapItem(QObject*     parent,
                                                 IController* controller,
                                                 IModel*      model)
: QObject(parent)
, IView(controller, model)
{
}

void IViewGraphicsPixmapItem::setNewModel(IModel* model)
{
    if (getModel() != nullptr) {
        QObject::disconnect(getModel(), 0, this, 0);
    }

    setModel(model);

    if (getModel() != nullptr) {
        connectModelView();
    }

    update();
}
