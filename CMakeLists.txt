cmake_minimum_required(VERSION 3.14)
project(AS4)

set(CMAKE_CXX_STANDARD 14)

add_executable(AS4 TESTING.cpp
                src/borrow.h
                src/bst.h
                src/classic.cpp
                src/classic.h
                src/comedy.cpp
                src/comedy.h
                src/customer.cpp
                src/customer.h
                src/drama.cpp
                src/drama.h
                src/drama.cpp
                src/hash.h
                src/hash.cpp
                src/history.h
                src/inventory.h
                src/movie.cpp
                src/movie.h
                src/return.h
                src/transaction.h
                src/nodedata.h
                src/nodedata.cpp)