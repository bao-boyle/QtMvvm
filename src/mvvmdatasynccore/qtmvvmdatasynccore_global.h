#ifndef QTMVVMDATASYNCCORE_GLOBAL_H
#define QTMVVMDATASYNCCORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QT_BUILD_MVVMDATASYNCCORE_LIB)
#	define Q_MVVMDATASYNCCORE_EXPORT Q_DECL_EXPORT
#else
#	define Q_MVVMDATASYNCCORE_EXPORT Q_DECL_IMPORT
#endif

#endif // QTMVVMDATASYNCCORE_GLOBAL_H