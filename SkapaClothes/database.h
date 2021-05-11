#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

class BaseDeDatos {
private:
    char *nomBD;
    sqlite3 *db;
    sqlite3_stmt *stmt;

public:
BaseDeDatos(char *nomBD);

#endif // DATABASE_H_INCLUDED
