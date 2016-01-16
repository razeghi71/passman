#include<Application.h>

string Application::getExecutablePath() const
{
    return executable_path;
}

string Application::getExecutableHash() const
{
    return executable_hash;
}
