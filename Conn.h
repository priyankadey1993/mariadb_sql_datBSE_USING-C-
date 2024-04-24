#include<iostream>
#include <mysql.h>
#include <iomanip>
#include<vector>
#include <string>
using namespace std;

struct connectiondetail{
	const char *server,*user,*password,*database;
};

MYSQL* mysql_connection_setup(struct connectiondetail mysqldetail);
MYSQL_RES *mysql_execute_query(MYSQL *connection,const char *sql_query);