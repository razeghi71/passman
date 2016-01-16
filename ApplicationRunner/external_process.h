#ifndef EXTERNALPROCESS_H
#define EXTERNALPROCESS_H

#include <QString>
#include <QProcess>

class ExternalProcess
{
private:
    QProcess process;
protected:
    QString command;
public:
    void run();
    QString getCommand();
};

#endif // EXTERNALPROCESS_H
