#!/bin/bash
cmake .
make
valgrind ./AS4
