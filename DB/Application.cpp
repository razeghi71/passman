#include "Application.h"

string Application::getExecutablePath() const
{
    return executablePath;
}

void Application::setExecutablePath(const string &value)
{
    executablePath = value;
}

string Application::getExecutableHash() const
{
    return executableHash;
}

void Application::setExecutableHash(const string &value)
{
    executableHash = value;
}

int Application::getAppId() const
{
    return appId;
}

Application::Application(string executable_path, string executable_hash)
{
    this->executableHash = executable_hash;
    this->executablePath = executable_path;
}
