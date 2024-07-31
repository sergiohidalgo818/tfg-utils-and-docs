CC := g++
CCC:= gcc
SRCDIR := src/
SRCTESTS := src/tests/
INCL := include/
INCLTESTS := include/tests/
BUILDDIR := build/
TARGET := bin/runner/
LIB_TEST := -lcppunit 
.PHONY: clean


make: create_dirs main

create_dirs:
	mkdir -p bin | mkdir -p bin/runner | mkdir -p build | mkdir -p data | mkdir -p measures

main: create_dirs main_cpp main_c main_cppinc



tests: create_dirs model_tests HindmarshRose_tests

model_tests: $(SRCTESTS)Model_tests.cpp Model.o ModelTest.o $(INCLTESTS)ModelTest.h
	$(CC) $(SRCTESTS)Model_tests.cpp -o $(TARGET)Model_tests $(LIB_TEST) $(BUILDDIR)Model.o  $(BUILDDIR)ModelTest.o

ModelTest.o: $(SRCTESTS)ModelTest.cpp $(INCLTESTS)ModelTest.h 
	$(CC) -c  $(SRCTESTS)ModelTest.cpp -o $(BUILDDIR)ModelTest.o 


HindmarshRose_tests: $(SRCTESTS)HindmarshRose_tests.cpp HindmarshRose.o HindmarshRosetest.o $(INCLTESTS)HindmarshRosetest.h
	$(CC) $(SRCTESTS)HindmarshRose_tests.cpp -o $(TARGET)HindmarshRose_tests $(LIB_TEST) $(BUILDDIR)Model.o $(BUILDDIR)HindmarshRose.o $(BUILDDIR)HindmarshRosetest.o 

HindmarshRosetest.o: $(SRCTESTS)HindmarshRosetest.cpp $(INCLTESTS)HindmarshRosetest.h 
	$(CC) -c  $(SRCTESTS)HindmarshRosetest.cpp -o $(BUILDDIR)HindmarshRosetest.o 


main_cpp: $(SRCDIR)main_cpp.cpp Model.o HindmarshRose.o $(INCL)HindmarshRose.h 
	$(CC) $(SRCDIR)main_cpp.cpp -o $(TARGET)main_cpp $(BUILDDIR)Model.o $(BUILDDIR)HindmarshRose.o 

Model.o: $(SRCDIR)Model.cpp $(INCL)Model.h 
	$(CC) -c  $(SRCDIR)Model.cpp -o $(BUILDDIR)Model.o 

HindmarshRose.o: $(SRCDIR)HindmarshRose.cpp $(INCL)HindmarshRose.h $(INCL)Model.h 
	$(CC) -c  $(SRCDIR)HindmarshRose.cpp -o $(BUILDDIR)HindmarshRose.o 


main_c: $(SRCDIR)main_c.c hindmarsh_rose.o $(INCL)hindmarsh_rose.h 
	$(CC) $(SRCDIR)main_c.c -o $(TARGET)main_c $(BUILDDIR)hindmarsh_rose.o 

hindmarsh_rose.o: $(SRCDIR)hindmarsh_rose.c $(INCL)hindmarsh_rose.h 
	$(CC) -c  $(SRCDIR)hindmarsh_rose.c -o $(BUILDDIR)hindmarsh_rose.o


main_cppinc: $(SRCDIR)main_cppinc.cpp hindmarsh_rose_cppinc.o $(INCL)hindmarsh_rose.h 
	$(CC) $(SRCDIR)main_cppinc.cpp -o $(TARGET)main_cppinc $(BUILDDIR)hindmarsh_rose_cppinc.o 

hindmarsh_rose_cppinc.o: $(SRCDIR)hindmarsh_rose_cppinc.cpp $(INCL)hindmarsh_rose.h 
	$(CC) -c  $(SRCDIR)hindmarsh_rose_cppinc.cpp -o $(BUILDDIR)hindmarsh_rose_cppinc.o 


clean: clean_all
clean_all: clean_objects clean_runners
clean_objects:
	rm -f $(BUILDDIR)* 
clean_runners:
	rm -f $(TARGET)* 