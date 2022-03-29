cmake_minimum_required(VERSION 3.0.0)

project(Calculator_Project VERSION 2.0.0)




find_package (SQLite3)



add_executable(exec driver.cpp)



target_link_libraries(exec LINK_PUBLIC sqlite3)




