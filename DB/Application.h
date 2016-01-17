#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <odb/core.hxx>
using namespace std;

#pragma db object
class Application
{
  friend class odb::access;
  Application () {}

  #pragma db id
  int app_id;

  string executable_path;
  string executable_hash;
public :
  Application(string executable_path, string executable_hash);
  string getExecutablePath() const;
  string getExecutableHash() const;

  void setExecutableHash(const string &value);
  void setExecutablePath(const string &value);
};

#endif
