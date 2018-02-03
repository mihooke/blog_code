#ifndef MIKPLUGIN_H
#define MIKPLUGIN_H

#include "mikplugin_global.h"
#include "plugininterface.h"
#include <QObject>
#include <QDebug>

class MIKPLUGINSHARED_EXPORT MikPlugin : public QObject, MikPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID MikPlugin_IID FILE "mikPlugin.json")
    Q_INTERFACES(MikPluginInterface)

public:
    void hello(const char *str);
};

#endif // MIKPLUGIN_H
