#ifndef TABLEOPERATION_H
#define TABLEOPERATION_H

#include"Conn.h"
class TableOperation
{
	
	int num_colum =2;
	vector<string> colum;
	vector<string> col;
	public:
		TableOperation();
	
    void create_table(string str,MYSQL *con,MYSQL_RES *res,MYSQL_ROW row);
	void insert_table(string str,MYSQL *con,MYSQL_RES *res,MYSQL_ROW row);
	void Show_table(string str,MYSQL *con,MYSQL_RES *res,MYSQL_ROW row);	
	void drop_table(string str,MYSQL *con,MYSQL_RES *res,MYSQL_ROW row);
};

#endif