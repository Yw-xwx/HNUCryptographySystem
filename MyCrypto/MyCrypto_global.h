#ifndef MYCRYPTO_GLOBAL_H
#define MYCRYPTO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MYCRYPTO_LIBRARY)
#  define MYCRYPTO_EXPORT Q_DECL_EXPORT
#else
#  define MYCRYPTO_EXPORT Q_DECL_IMPORT
#endif

#endif // MYCRYPTO_GLOBAL_H
