#include "Conn.h"
MYSQL* mysql_connection_setup(struct connectiondetail mysqldetail)
{
     
    int    MY_PORT_NO = 3306;
    int    MY_OPT     = 0;
    
   //  mysqldetail.MY_SOCKET = NULL;
	MYSQL *connection = mysql_init(NULL);
    if(!mysql_real_connect(connection,mysqldetail.server,mysqldetail.user,mysqldetail.password,mysqldetail.database,MY_PORT_NO,NULL,MY_OPT))
	{
		cout<<"connection error"<<mysql_error(connection)<<endl;
	//	exit(1);
	}	
	return connection;
}

MYSQL_RES *mysql_execute_query(MYSQL *connection,const char *sql_query)
{
	if(mysql_query(connection,sql_query))
	{
		cout<<"mysql_query error"<<mysql_error(connection)<<endl;
	}
	
	return mysql_use_result(connection);
}