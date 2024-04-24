#include "TableOperation.h"

TableOperation::TableOperation()
{
}

void TableOperation::Show_table(string str ,MYSQL *con,MYSQL_RES *res,MYSQL_ROW row)
{
	string s="select * from "+str;
	const char* sql_qury= s.c_str();
	res=mysql_execute_query(con,sql_qury);
	int i=0;
   cout<<"displaying database output"<<endl;
   while((row = mysql_fetch_row(res)) != NULL && i<=num_colum)
    {
    	cout<<i<<endl;
		cout<<row[i]<<"|"<<row[i+1];
	
	}
    cout<<endl;
    
}


void TableOperation::create_table(string str ,MYSQL *con,MYSQL_RES *res,MYSQL_ROW row)
{   string query = "CREATE TABLE "+str +"(";
    for(int i=0;i<2;i++)
    {
    	string colum_name,colum_type;
    	cout<<"enter the colum name"<<endl;
    	cin>>colum_name;
    	
    	cout<<"enter the colum TYPE  (e.g., INT, VARCHAR(50))"<<endl;
    	cin>>colum_type;
    	
    	col.push_back(colum_name);
    	colum.push_back(colum_name+" "+ colum_type);
	}
	
	for(int i=0;i<colum.size();i++)
	{
		query+= colum[i];
		if(i==0)
		{
			query+=" PRIMARY KEY";
		}
		if(i!=colum.size()-1)
		query+=", ";
	}
	query+=")";
	cout<<query<<endl;
	const char* sql_qury= query.c_str();
	
    res=mysql_execute_query(con,sql_qury);
	//cout<<"create_table"<<endl;
    

}

void TableOperation::insert_table(string str ,MYSQL *con,MYSQL_RES *res,MYSQL_ROW row)
{
	string values;
	cout << "Enter values to insert (comma-separated):"<<col[0]<<col[1];
    cin.ignore(); // Ignore newline character left in the buffer from previous input
    getline(cin, values);
	
    string query = "INSERT INTO " + str + " VALUES (" + values + ")";
      if (mysql_query(con, query.c_str())) {     
	    cerr << "Error: " << mysql_error(con) << endl;
    }
}

void TableOperation::drop_table(string str ,MYSQL *con,MYSQL_RES *res,MYSQL_ROW row)
{
	 string query = "DROP TABLE " + str;

    if (mysql_query(con, query.c_str())) {
        cerr << "Error: " << mysql_error(con) << endl;
        return;
    }

    cout <<str<<" Table dropped successfully." << endl;
}


