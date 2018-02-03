#include "handleclass.h"
#include "ui_handleclass.h"

HandleClass::HandleClass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HandleClass)
{
    ui->setupUi(this);
    connect(&m_thread, &QThread::started, &ThreadClass::single(), &ThreadClass::start);
    connect(&m_thread, &QThread::finished, &ThreadClass::single(), &QObject::deleteLater);
    /// ThreadClass object move to thread
    ThreadClass::single().moveToThread(&m_thread);
    m_thread.start();
}

HandleClass::~HandleClass()
{
    delete ui;
    /// As general, we should invoke quit() and wait() to finish the thread
    /// But we cannot invoke them for keeping the thread alive
//    m_thread.quit();
//    m_thread.wait();
}

