#include<Application.h>

Application::Application(string executable_path, string executable_hash)
{
    this->executable_hash = executable_hash;
    this->executable_path = executable_path;
}

void Application::setExecutableHash(const string &value)
{
    executable_hash = value;
}

void Application::setExecutablePath(const string &value)
{
    executable_path = value;
}

string Application::getExecutablePath() const
{
    return executable_path;
}

string Application::getExecutableHash() const
{
    return executable_hash;
}
