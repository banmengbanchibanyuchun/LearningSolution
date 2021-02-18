#ifndef OBJECTA_GLOBAL_H
#define OBJECTA_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(OBJECTA_LIBRARY)
#  define OBJECTA_EXPORT Q_DECL_EXPORT
#else
#  define OBJECTA_EXPORT Q_DECL_IMPORT
#endif

#endif // OBJECTA_GLOBAL_H
