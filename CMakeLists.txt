cmake_minimum_required(VERSION 3.7)
project(AS4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

add_executable(AS4
                src/store.h
                src/store.cpp
                src/bst.hpp
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
                src/movie.h
                src/movie.cpp
                src/nodedata.h
                src/nodedata.cpp)
