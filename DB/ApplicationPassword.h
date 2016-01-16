#ifndef APPLICATION_PASSWORD_H
#define APPLICATION_PASSWORD_H

#include <string>
#include <odb/core.hxx>
#include "Application.h"
#include <odb/nullable.hxx>

using namespace std;

#pragma db object
class ApplicationPassword
{
  friend class odb::access;
  ApplicationPassword () {}

  #pragma db id
  int passwordID;

  Application* app;
  odb::nullable<std::string> title;
  odb::nullable<std::string> url;
  odb::nullable<std::string> username;
  string password;
};

#endif
