cmake_minimum_required(VERSION 3.13.2)
project(AS4)

set(CMAKE_CXX_STANDARD 14)

add_executable(AS4
        src/borrow.h
        src/borrow.cpp
        src/bst.hpp
        src/classic.cpp
        src/classic.h
        src/comedy.cpp
        src/comedy.h
        src/customer.cpp
        src/customer.h
        src/drama.cpp
        src/drama.h
        src/hash.h
        src/hash.cpp
        src/history.h
        src/history.cpp
        src/inventory.h
        src/movie.cpp
        src/movie.h
        src/return.h
        src/return.cpp
        src/transaction.h
        src/transaction.cpp
        src/nodedata.h
        src/nodedata.cpp
        src/store.cpp
        src/store.h)