#ifndef DB_H
#define DB_H

#include "Application.h"
#include "Application-odb.hxx"
#include "ApplicationPassword.h"
#include "ApplicationPassword-odb.hxx"
#include <odb/mysql/database.hxx>
#include <odb/transaction.hxx>
#include <QString>

typedef odb::query<Application> ApplicationQuery;
typedef odb::result<Application> ApplicationResult;

typedef odb::query<ApplicationPassword> ApplicationPasswordQuery;
typedef odb::result<ApplicationPassword> ApplicationPasswordResult;

class DB
{
    static odb::database *db;
public:
    static void connect(QString username, QString password, QString dbname);
    static odb::database* getDB();
};



#endif // DB_H
