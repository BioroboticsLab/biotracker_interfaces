#pragma once

#include <QObject>
#include <Interfaces/API.h>

class BT_INTERFACES_API ENUMS : public QObject
{
    Q_OBJECT
public:
    enum CONTROLLERTYPE : unsigned int
    {
        NO_CTR,
        MAINWINDOW,
        TEXTUREOBJECT,
        PLAYER,
        COMPONENT,
        TRACKING,
        GRAPHICSVIEW,
        TRACKEDCOMPONENTCORE,
        PLUGIN,
        DATAEXPORT,
        ANNOTATIONS,
        AREADESCRIPTOR,
        COREPARAMETER,
        COMMANDS,
        NOTIFICATION
    };
    Q_ENUM(CONTROLLERTYPE)

    enum COREPERMISSIONS : unsigned int
    {
        COMPONENTVIEW,
        COMPONENTMOVE,
        COMPONENTREMOVE,
        COMPONENTSWAP,
        COMPONENTADD,
        COMPONENTROTATE
    };
    Q_ENUM(COREPERMISSIONS)
};
