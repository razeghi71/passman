#ifndef GROUP_H
#define GROUP_H

#include <QString>

class Group
{
    QString groupName;
public:
    Group(QString groupName);

    QString getGroupName() const;
    void setGroupName(const QString &value);
};

#endif // GROUP_H
