#ifndef DB_H
#define DB_H

#include "Application-odb.hxx"
#include "Application.h"
#include "ApplicationPassword-odb.hxx"
#include "ApplicationPassword.h"
#include <odb/mysql/database.hxx>
#include <odb/transaction.hxx>
#include <QString>

typedef odb::query<Application> ApplicationQuery;
typedef odb::result<Application> ApplicationResult;

typedef odb::query<Application> ApplicationPasswordQuery;
typedef odb::result<Application> ApplicationPasswordResult;

class DB
{
    static auto_ptr<odb::database> db;
public:
    static void connect(QString username, QString password, QString dbname);
    static auto_ptr<odb::database> getDB();
};

#endif // DB_H
