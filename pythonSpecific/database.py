import sqlite3



def store(task):
    # Create the sqlite database if it does not exist. If it exist, connect to it.
    try:
        conn = sqlite3.connect('database.db')
    except Error as e:
        print(e)

    # Create a cursor to allow to execute SQL commands
    cursor = conn.cursor()


    # Create a SQL Table
    sql_command = '''
        CREATE TABLE IF NOT EXISTS SESSION_TABLE (
            ID INTEGER PRIMARY KEY AUTOINCREMENT, 
        NUMBER1   TEXT NOT NULL, 
        NUMBER2   TEXT NOT NULL, 
        OPERATION_PERFORMED   TEXT  NOT NULL, 
        RESULT   TEXT  NOT NULL 
        )'''
    cursor.execute(sql_command)


    insert_data = ''' INSERT INTO SESSION_TABLE(NUMBER1, NUMBER2, OPERATION_PERFORMED, RESULT)
                VALUES(?,?,?,?) '''


    cursor.execute(insert_data,task)
    # Commit the changes to the database
    conn.commit()

    select_data = 'SELECT * FROM SESSION_TABLE'
    cursor.execute(select_data)

    rows = cursor.fetchall()
    
    print("\n\n**************** DATABASE TABLE STATE *****************\n")
    for row in rows:
        print(row )
    
    print('\n\n')

    # Close the Database
    conn.close()
