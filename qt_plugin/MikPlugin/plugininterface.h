#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QtPlugin>

#define MikPlugin_IID "mihooke.163.com"

class MikPluginInterface
{
public:
    virtual void hello(const char *str) = 0;
};

Q_DECLARE_INTERFACE(MikPluginInterface, MikPlugin_IID)

#endif // PLUGININTERFACE_H
