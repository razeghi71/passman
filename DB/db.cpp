#include "db.h"


void DB::connect(QString username, QString password, QString dbname)
{
    db = auto_ptr<odb::database>(new odb::mysql::database(
                                     username.toStdString().c_str(),
                                     password.toStdString().c_str(),
                                     dbname.toStdString().c_str())
                                 );
}

auto_ptr<odb::database> DB::getDB()
{
    return DB::db;
}
