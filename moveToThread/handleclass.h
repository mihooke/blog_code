#ifndef HANDLECLASS_H
#define HANDLECLASS_H

#include <QDialog>
#include <QThread>

namespace Ui {
class HandleClass;
}

class ThreadClass : public QObject
{
    Q_OBJECT
public:
    ThreadClass() = default;
    ~ThreadClass() = default;

    static ThreadClass &single()
    {
        static ThreadClass single;
        return single;
    }

public slots:
    void start() {}
};

class HandleClass : public QDialog
{
    Q_OBJECT

public:
    explicit HandleClass(QWidget *parent = 0);
    ~HandleClass();

public slots:
    void start() {}

private:
    Ui::HandleClass *ui;
    QThread m_thread;
};

#endif // HANDLECLASS_H
