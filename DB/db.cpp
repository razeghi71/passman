#include "db.h"

odb::database *DB::db = 0;

void DB::connect(QString username, QString password, QString dbname)
{
    db = new odb::mysql::database(username.toStdString().c_str(),
                                  password.toStdString().c_str(),
                                  dbname.toStdString().c_str());
}

odb::database* DB::getDB()
{
    return db;
}

