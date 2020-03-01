#pragma once

#include <QtGlobal>

#if defined(BT_INTERFACES_EXPORT)
    #define BT_INTERFACES_API Q_DECL_EXPORT
#else
    #define BT_INTERFACES_API Q_DECL_IMPORT
#endif