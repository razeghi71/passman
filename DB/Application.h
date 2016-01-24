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

  #pragma db id auto
  int appId;

  string executablePath;
  string executableHash;
public :
  Application(string executablePath, string executableHash);

  string getExecutablePath() const;
  void setExecutablePath(const string &value);
  string getExecutableHash() const;
  void setExecutableHash(const string &value);
  int getAppId() const;
};

#endif
