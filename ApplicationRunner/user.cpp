#include "user.h"

User::User(const User &user)
{
    setUserName(user.getUserName());
}

User::User(QString userName)
{
    setUserName(userName);
}

QString User::getUserName() const
{
    return userName;
}

void User::setUserName(const QString &value)
{
    userName = value;
}
