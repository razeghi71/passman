#ifndef USER_H
#define USER_H

#include <QString>

class User
{
    QString userName;
public:
    User(QString userName);
    QString getUserName() const;
    void setUserName(const QString &value);
};

#endif // USER_H
