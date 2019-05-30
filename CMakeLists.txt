cmake_minimum_required(VERSION 3.14)
project(AS4)

set(CMAKE_CXX_STANDARD 14)

include_directories(data)
include_directories(src)

add_executable(AS4
        data/data4commands.txt
        data/data4customers.txt
        data/data4movies.txt
        src/borrow.h
        src/customer.cpp
        src/customer.h
        src/hash.cpp
        src/hash.h
        src/history.h
        src/inventory.h
        src/movies.h
        src/movies.cpp
        src/comedy.h
        src/drama.h
        src/classic.h
        src/nodedata.cpp
        src/nodedata.h
        src/return.h
        src/transaction.h
        TESTING.cpp)
