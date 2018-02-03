#include <QCoreApplication>
#include <QPluginLoader>
#include<QDebug>
#include "plugininterface.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject *object;
    a.addLibraryPath(QString("../build-MikPlugin-Desktop_Qt_5_8_0_MSVC2015_64bit-Debug/debug"));
    QPluginLoader l(QString("MikPlugin")) ;

    if ( (object=l.instance()) != NULL )
    {
        qDebug("plugin loaded .");
        MikPluginInterface* plugin = qobject_cast<MikPluginInterface*>(object) ;
        if (plugin)
            plugin->hello("hello plugin");
    }
    else
    {
        qDebug("failed to load plugin !! ");
        QString errorStr = l.errorString();
        qDebug()<<errorStr;
    }

    return a.exec();
}
