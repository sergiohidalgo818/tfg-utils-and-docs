CC := g++
SRCDIR := src/
SRCTESTS := src/tests/
INCL := include/
INCLTESTS := include/tests/
BUILDDIR := build/
TARGET := bin/runner/
LIB_TEST := -lcppunit 
.PHONY: clean


make: create_dirs main hindmarsh-rose

create_dirs:
	mkdir -p bin | mkdir -p bin/runner | mkdir -p build

main: main


compilar: create_dirs main


make_tests: tests

tests: hindmarsh-rose_tests 

hindmarsh-rose_tests: $(SRCTESTS)hindmarsh-rose_tests.cpp hindmarsh-rose.o hindmarsh-rosetest.o $(INCLTESTS)hindmarsh-rosetest.h
	$(CC) $(SRCTESTS)hindmarsh-rose_tests.cpp -o $(TARGET)hindmarsh-rose_tests $(LIB_TEST) $(BUILDDIR)hindmarsh-rose.o $(BUILDDIR)hindmarsh-rosetest.o

hindmarsh-rosetests.o: $(SRCTESTS)hindmarsh-rosetest.cpp $(INCLTESTS)hindmarsh-rosetest.h 
	$(CC) -c  $(SRCTESTS)hindmarsh-rosetest.cpp -o $(BUILDDIR)hindmarsh-rosetest.o 


main: $(SRCDIR)main.cpp hindmarsh-rose.o $(INCL)hindmarsh-rose.h
	$(CC) $(SRCDIR)main.cpp -o $(TARGET)main $(BUILDDIR)hindmarsh-rose.o  

hindmarsh-rose.o: $(SRCDIR)hindmarsh-rose.cpp $(INCL)forwarding.h $(INCL)hindmarsh-rose.h $(INCL)connection.h
	$(CC) -c  $(SRCDIR)hindmarsh-rose.cpp -o $(BUILDDIR)hindmarsh-rose.o 


clean: clean_all
clean_all: clean_objects clean_runners
clean_objects:
	rm -f $(BUILDDIR)* 
clean_runners:
	rm -f $(TARGET)* 