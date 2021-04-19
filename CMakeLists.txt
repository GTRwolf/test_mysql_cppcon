cmake_minimum_required(VERSION 3.17)
project(test_mysql_cppcon)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -fPIC")

include_directories(include)
link_directories(lib)

add_executable(test_mysql_cppcon main.cpp)
target_link_libraries(test_mysql_cppcon mysqlcppconn pthread)