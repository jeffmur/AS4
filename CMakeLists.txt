cmake_minimum_required(VERSION 3.13)
project(AS4)
SET(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(AS4
        src/borrow.h
        src/classic.cpp
        src/classic.h
        src/comedy.cpp
        src/comedy.h
        src/customer.cpp
        src/customer.h
        src/drama.cpp
        src/drama.h
        src/hash.cpp
        src/hash.h
        src/history.h
        src/inventory.h
        src/movie.cpp
        src/movie.h
        src/nodedata.cpp
        src/nodedata.h
        src/return.h
        src/transaction.h
        src/bstree.h
        src/bst.h
        TESTING.cpp)
