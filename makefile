# Makefile HW4 600.120 Spring 2015
# JHED: amehndi1
# Name: Anuj Mehndiratta
# Date: April 2, 2016

# Lines starting with # are comments

# Some variable definitions to save typing later on
CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

# Compiles hw4a into an object file
hw4a.o: hw4a.cpp
	$(CC) $(CFLAGS) -c hw4a.cpp

# Compiles test_hw3methods.c into an object file
test_hw4a.o: test_hw4a.cpp
	$(CC) $(CFLAGS) -c test_hw4a.cpp

# Compiles test_hw3methods.c into an object file
test_hw4b.o: test_hw4b.cpp
	$(CC) $(CFLAGS) -c test_hw4b.cpp

# Compiles hw3.c into an object file
hw4b.o: hw4b.cpp
	$(CC) $(CFLAGS) -c hw4b.cpp

# 'make clean' will remove intermediate & executable files
clean:
	rm -f *.o test_hw4a hw4a hw4b test_hw4b *.gcov
