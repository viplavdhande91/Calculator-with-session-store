# Calculator with Session Storing Feature 

This Calculator system performs Arithmetic Operations and caches the session into database table.

## Prerequisites
* sqlite3

## Build instructions for Ubuntu 20.04 LTS
### Setup
```
sudo apt install build-essential libsqlite3-dev
```
### Compiling
``` 
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=debug
make exec
```
### Runing
``` 
./exec
```

### Test with
* gcc 11
* cmake 3.0.0
* Sqlite3 3.31.1

    
## API Reference

### Database Table Structure


| NUMBER1 | NUMBER2     | OPERATION_PERFORMED   | RESULT |
| :-------- | :------- | :--------------------- |:------ |
|         |            |                        |        |


## Authors

- [@Viplav Patil](https://www.linkedin.com/in/viplav-patil-a5789028/)


## Feed back from @ruvi-d
* project wasn't in a compiling state
* remove every `using namespace`
* provide design doc: class diagram / sequence diagram
  * we can review code after reviewing the design
* organize source files in to a src/ folder
* unit tests
* use clang-format to format files
* clean up and sort includes