#ifndef FREMLESSWIDGET_GLOBAL_H
#define FREMLESSWIDGET_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FREMLESSWIDGET_LIBRARY)
#  define FREMLESSWIDGET_EXPORT Q_DECL_EXPORT
#else
#  define FREMLESSWIDGET_EXPORT Q_DECL_IMPORT
#endif

#endif // FREMLESSWIDGET_GLOBAL_H
