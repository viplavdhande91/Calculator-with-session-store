# Calculator with Session Storing Feature 



## Run Calculator

  This Calculator system performs Arithmetic Operations and caches
  the session into database table.
  
1)Visit [SQLite Download Page](https://www.sqlite.org/download.html) and download
sqlite-amalgamation-3380200.zip thereafter Copy-paste sqlite3.h and sqlite3.c
into root directory of Project.


2)Create Build Directory

``` 
mkdir build

```
3)Navigate to build
``` 
cd build
```

4)Linking Project Files using CMakeLists
``` 
cmake ..

```

5)Build the Project
``` 
make
```


6)Execute the Calculator Executable
``` 
./exec
```





## Unit Testing

1)Navigate to testing
``` 
cd testing
```

2)Create Build Directory

``` 
mkdir build

```
3)Navigate to build
``` 
cd build
```

4)Linking Project Files using CMakeLists
``` 
cmake ..

```

5)Build the Project
``` 
make
```

6)Navigate to test_calculator
``` 
cd test_calculator
```
7)Run test Executable
``` 
.\test_calculator
```
    
## API Reference

#### Database Table Structure


| NUMBER1 | NUMBER2     | OPERATION_PERFORMED   | RESULT |
| :-------- | :------- | :--------------------- |:------ |
|         |            |                        |        |





## Third Party Libraries


1)Used [libsqlite3-dev](https://packages.ubuntu.com/bionic-updates/libsqlite3-dev)
[SQLite 3 development files] , [sqlite3](https://www.sqlite.org/docs.html)
``` 
sudo apt-get install sqlite3 libsqlite3-dev
```



## Versions

1)C++
``` 
 version: 11
```
2)cmake
``` 
 version: 3.0.0

```
3)Sqlite3

```
version: 3.31.1
```


## License

[MIT](https://choosealicense.com/licenses/mit/) 
Licensed under Distribution Category


## Authors

- [@Viplav Patil](https://www.linkedin.com/in/viplav-patil-a5789028/)

## Review comments
* You are supposed to merge my review PR
* Commit messages are still not in "imperative mood"
* Still not using the project template I shared
* You should be compiling with extra warnings
* Give a meaningful name to the executable
* missing clang format 
* Test files should be next to the files under test
* driver cpp need to be split to 1) DB access logic 2) CLI parsing logic 3) calculations and then tested separately 