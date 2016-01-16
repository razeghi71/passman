#include "group.h"

Group::Group(QString groupName)
{
    setGroupName(groupName);
}

QString Group::getGroupName() const
{
    return groupName;
}

void Group::setGroupName(const QString &value)
{
    groupName = value;
}
