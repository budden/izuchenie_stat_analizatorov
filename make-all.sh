#!/bin/bash
set -x -e
cd leontqev1
g++ -Wall leontqev1.cpp \
 test1_cpp/test1.cpp \
 test2_cpp/test2.cpp \
 test3_cpp/test3.cpp \
 test4_cpp/test4.cpp \
 test5_cpp/test5.cpp \
 test6_cpp/test6.cpp \
 test7_cpp/test7.cpp \
 test1_c/test1.c \
 test2_c/test2.c \
 test3_c/test3.c \
 test4_c/test4.c \
 test6_c/test6.c \
 -o leontqev1.o
