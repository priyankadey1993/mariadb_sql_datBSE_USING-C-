#include "TableOperation.h"
void printmenu()
{
	cout<<"welcome to the tble creation menu"<<endl;
	cout<<"create new table press 1"<<endl;
	cout<<"insert to table press 2"<<endl;
	cout<<"show the table press 3"<<endl;
	cout<<"drop the table press 4"<<endl;
}

int main(int argc, char** argv) 
{
	MYSQL *con;
	MYSQL_RES *res;
	MYSQL_ROW row;	
	struct connectiondetail mysqlD;
    mysqlD.server="localhost";
    mysqlD.user="root";
    mysqlD.password="password";
    mysqlD.database="test";
    con=mysql_connection_setup(mysqlD);
    string str;
	
    bool flag =0;
    TableOperation table_obj;
    int ch;
  
    res=mysql_execute_query(con,"SHOW TABLES ");
   
    while((row = mysql_fetch_row(res)) != NULL)
    {
		cout<<row[0]<<endl;
	}
	cout<<"enter a table name"<<endl;
    cin>>str;
	 
    while(1)
    {
    	
       printmenu();
       cout<<"enter your choice"<<endl;
       cin>>ch;
       switch(ch)
       {
       	case 1:	if(flag==0)
               	{
               		table_obj.create_table(str,con,res,row);
               		flag=1;
				}
				else
				{
					cout<<"already created table"<<endl;
				}
				break;
				
		case 2:
			    if(flag==1)
		        	table_obj.insert_table(str,con,res,row);
				else
					cout<<"table is not created"<<endl;
				break;
		
		case 3:	
		        if(flag==1)
		        	table_obj.Show_table(str,con,res,row);
				else
					cout<<"table is not created"<<endl;
				break;
		case 4: 
		        if(flag == 1) 
				{
					table_obj.drop_table(str,con,res,row);
				}
				else
				{
					cout<<"table not crreated"<<endl;
				}
				break;		    
		
		   
	   	}
	
	}
	 mysql_close(con);
	return 0;
}
    
    
    
	/*res=mysql_execute_query(con,"select * from book ");
    cout<<"dispalying database output"<<endl;
    cout<<"BookID"<<"   |   "<<"Title"<<"  |   "<<"authorID"<<" | "<<endl;
    while((row = mysql_fetch_row(res)) != NULL)
    {
    	cout<<row[0]<<setw(3)<<"|"<<row[1]<<setw(3)<<"|"<<row[2]<<"|"<<endl;
    	cout<<"-------------------------------------"<<endl;
    	
	}*/
    
	 
    
   


/*
	res=mysql_execute_query(con," INSERT INTO book (BookID,Title,AuthorID) values(8 , 'alice the wonderlabd',8)");
	while((row = mysql_fetch_row(res)) != NULL)
    {
    	cout<<row[0]<<"    |    "<<row[1]<<" | "<<row[2]<<"   |   "<<endl;
	}*/
	
	/*
	res=mysql_execute_query(con,"delete from book where BookID = 7");
	while((row = mysql_fetch_row(res)) != NULL)
    {
    	cout<<row[0]<<"    |    "<<row[1]<<" | "<<row[2]<<"   |   "<<endl;
	}
	
	res=mysql_execute_query(con," Update book SET Title = "greate science" where Title = " The Fellowship of the Ring");
	while((row = mysql_fetch_row(res)) != NULL)
    {
    	cout<<row[0]<<"    |    "<<row[1]<<" | "<<row[2]<<"   |   "<<endl;
	}
	
	
*/