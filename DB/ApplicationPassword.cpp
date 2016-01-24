#include "ApplicationPassword.h"



ApplicationPassword::ApplicationPassword(Application *app, odb::nullable<std::string> username, std::vector<unsigned char> password)
{
    this->app = app;
    this->username = username;
    this->password = password;
}

std::vector<unsigned char> ApplicationPassword::getPassword() const
{
    return password;
}

void ApplicationPassword::setPassword(const std::vector<unsigned char> &value)
{
    password = value;
}

Application *ApplicationPassword::getApp() const
{
    return app;
}

void ApplicationPassword::setApp(Application *value)
{
    app = value;
}

odb::nullable<std::string> ApplicationPassword::getUsername() const
{
    return username;
}

void ApplicationPassword::setUsername(const odb::nullable<std::string> &value)
{
    username = value;
}
