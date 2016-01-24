#ifndef APPLICATION_PASSWORD_H
#define APPLICATION_PASSWORD_H

#include <string>
#include <odb/core.hxx>
#include "Application.h"
#include <odb/nullable.hxx>
#include <vector>

using namespace std;

#pragma db object
class ApplicationPassword
{
  friend class odb::access;
  ApplicationPassword () {}

  #pragma db id auto
  int passwordID;

  Application *app;
  odb::nullable<std::string> username;

  #pragma db type("BLOB")
  std::vector<unsigned char> password;

public:
  ApplicationPassword(Application* app, odb::nullable<std::string> username, std::vector<unsigned char> password);


  Application *getApp() const;
  void setApp(Application *value);
  odb::nullable<std::string> getUsername() const;
  void setUsername(const odb::nullable<std::string> &value);

  int getPasswordID() const;

  std::vector<unsigned char> getPassword() const;
  void setPassword(const std::vector<unsigned char> &value);
};

#endif
