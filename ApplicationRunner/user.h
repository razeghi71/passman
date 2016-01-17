#ifndef USER_H
#define USER_H

#include <QString>

class User
{
    QString userName;
public:
    User(){}
    User(const User &user);
    User(QString userName);
    QString getUserName() const;
    void setUserName(const QString &value);
};

#endif // USER_H
