#include "sqlite3.h"
#include <stdio.h>
#include <iostream>
#include <sstream> //put this at the top
#include <time.h>
#pragma warning(disable : 4996)
using std::cout;
using std::endl;

#include <string>

static int createDB(const char *s)
{
	sqlite3 *DB;

	int exit = 0;
	exit = sqlite3_open(s, &DB);

	sqlite3_close(DB);

	return 0;
}

static int createTable(const char *s)
{
	sqlite3 *DB;
	char *messageError;

	string sql = "CREATE TABLE IF NOT EXISTS SESSION_TABLE("
				 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
				 "NUMBER1   TEXT NOT NULL, "
				 "NUMBER2   TEXT NOT NULL, "
				 "OPERATION_PERFORMED   TEXT  NOT NULL, "
				 "RESULT   TEXT  NOT NULL );";

	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK)
		{
			cerr << "Error in createTable function." << endl;
			cout << messageError << endl;
			sqlite3_free(messageError);
		}
		
		sqlite3_close(DB);
	}
	catch (const exception &e)
	{
		cerr << e.what();
	}

	return 0;
}

static int insertData(const char *s, string sql)
{
	sqlite3 *DB;
	char *messageError;

	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK)
	{
		cerr << "Error in insertData function." << endl;
		cout << messageError << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records inserted Successfully!" << endl;

	return 0;
}

// retrieve contents of database used by selectData()
/* argc: holds the number of results, argv: holds each value in array, azColName: holds each column returned in array, */
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{   
	for (int i = 0; i < argc; i++)
	{
		// column name and value
		cout << argv[i] << "      |";
	}

	cout << endl;

	return 0;
}
static int deleteData(const char *s)
{
	sqlite3 *DB;
	char *messageError;

	string sql = "DELETE FROM SESSION_TABLE;";

	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
	if (exit != SQLITE_OK)
	{
		cerr << "Error in deleteData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records deleted Successfully!" << endl;

	return 0;
}

static int selectData(const char *s)
{
	sqlite3 *DB;
	char *messageError;

	string sql = "SELECT * FROM SESSION_TABLE;";

	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
	cout<<"ID |"<<"NUMBER1 |"<<"NUMBER2 |"<<"OPERATION_PERFORMED |"<<"RESULT |"<<endl;

	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

	if (exit != SQLITE_OK)
	{
		cerr << "Error in selectData function." << endl;
		sqlite3_free(messageError);
	}
	

	return 0;
}

