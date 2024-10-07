CPPC := g++
CC:= gcc
SRCDIR := src/
TESTS := tests/
INCL := include/
BUILDDIR := build/
TARGET := bin/runner/
DATA := data/
LIB_TEST := -lcppunit 
LIB_MATH := -lm
CF:= c/
CPPF:= cpp/
CICPPF:= cincpp/
.PHONY: clean


make: create_dirs main

create_dirs: create_data_dirs
	mkdir -p bin | mkdir -p bin/runner | mkdir -p build | mkdir -p measures

create_data_dirs:
	mkdir -p data/executions_HR/c data/executions_RM/c data/executions_HR/cpp data/executions_RM/cpp data/executions_HR/cppinc data/executions_RM/cppinc data/timings_HR data/timings_RM

main: create_dirs main_hr_cpp main_hr_c main_hr_cppinc main_rm_cpp main_rm_c



tests: create_dirs model_tests HindmarshRose_tests 

model_tests: $(SRCDIR)$(CPPF)$(TESTS)Model_tests.cpp Model.o ModelTest.o $(INCL)$(CPPF)$(TESTS)ModelTest.h
	$(CPPC) $(SRCDIR)$(CPPF)$(TESTS)Model_tests.cpp -o $(TARGET)Model_tests $(LIB_TEST)$(BUILDDIR)Model.o  $(BUILDDIR)ModelTest.o

ModelTest.o: $(SRCDIR)$(TESTS)ModelTest.cpp $(TESTS)ModelTest.h 
	$(CPPC) -c  $(SRCDIR)$(TESTS)ModelTest.cpp -o $(BUILDDIR)ModelTest.o 


HindmarshRose_tests: $(SRCDIR)$(CPPF)$(TESTS)HindmarshRose_tests.cpp HindmarshRose.o HindmarshRosetest.o $(INCL)$(CPPF)$(TESTS)HindmarshRosetest.h
	$(CPPC) $(SRCDIR)$(CPPF)$(TESTS)HindmarshRose_tests.cpp -o $(TARGET)HindmarshRose_tests $(LIB_TEST) $(BUILDDIR)Model.o $(BUILDDIR)HindmarshRose.o $(BUILDDIR)HindmarshRosetest.o 

HindmarshRosetest.o: $(SRCDIR)$(CPPF)$(TESTS)HindmarshRosetest.cpp $(INCL)$(CPPF)$(TESTS)HindmarshRosetest.h 
	$(CPPC) -c  $(SRCDIR)$(CPPF)$(TESTS)HindmarshRosetest.cpp -o $(BUILDDIR)HindmarshRosetest.o 



Model.o: $(SRCDIR)$(CPPF)Model.cpp $(INCL)$(CPPF)Model.h 
	$(CPPC) -c  $(SRCDIR)$(CPPF)Model.cpp -o $(BUILDDIR)Model.o 

HindmarshRose.o: $(SRCDIR)$(CPPF)HindmarshRose.cpp $(INCL)$(CPPF)HindmarshRose.h $(INCL)$(CPPF)Model.h 
	$(CPPC) -c  $(SRCDIR)$(CPPF)HindmarshRose.cpp -o $(BUILDDIR)HindmarshRose.o 


RulkovMap.o: $(SRCDIR)$(CPPF)RulkovMap.cpp $(INCL)$(CPPF)RulkovMap.h $(INCL)$(CPPF)Model.h 
	$(CPPC) -c  $(SRCDIR)$(CPPF)RulkovMap.cpp -o $(BUILDDIR)RulkovMap.o 


rulkov_map.o: $(SRCDIR)$(CF)rulkov_map.c $(INCL)$(CF)rulkov_map.h 
	$(CC) -c  $(SRCDIR)$(CF)rulkov_map.c -o $(BUILDDIR)rulkov_map.o 


hindmarsh_rose.o: $(SRCDIR)$(CF)hindmarsh_rose.c $(INCL)$(CF)hindmarsh_rose.h 
	$(CC) -c  $(SRCDIR)$(CF)hindmarsh_rose.c -o $(BUILDDIR)hindmarsh_rose.o 


hindmarsh_rose_cppinc.o: $(SRCDIR)$(CICPPF)hindmarsh_rose_cppinc.cpp $(INCL)$(CF)hindmarsh_rose.h 
	$(CPPC) -c  $(SRCDIR)$(CICPPF)hindmarsh_rose_cppinc.cpp -o $(BUILDDIR)hindmarsh_rose_cppinc.o 


main_hr_cpp: $(SRCDIR)$(CPPF)main_hr_cpp.cpp Model.o HindmarshRose.o $(INCL)$(CPPF)HindmarshRose.h 
	$(CPPC) $(SRCDIR)$(CPPF)main_hr_cpp.cpp -o $(TARGET)main_hr_cpp $(BUILDDIR)Model.o $(BUILDDIR)HindmarshRose.o 

main_hr_cppinc: $(SRCDIR)$(CICPPF)main_hr_cppinc.cpp hindmarsh_rose_cppinc.o $(INCL)$(CF)hindmarsh_rose.h 
	$(CPPC) $(SRCDIR)$(CICPPF)main_hr_cppinc.cpp -o $(TARGET)main_hr_cppinc $(BUILDDIR)hindmarsh_rose_cppinc.o  

main_hr_c: $(SRCDIR)$(CF)main_hr_c.c hindmarsh_rose.o $(INCL)$(CF)hindmarsh_rose.h 
	$(CC) $(SRCDIR)$(CF)main_hr_c.c -o $(TARGET)main_hr_c $(BUILDDIR)hindmarsh_rose.o $(LIB_MATH)

main_rm_cpp: $(SRCDIR)$(CPPF)main_rm_cpp.cpp Model.o RulkovMap.o $(INCL)$(CPPF)RulkovMap.h 
	$(CPPC) $(SRCDIR)$(CPPF)main_rm_cpp.cpp -o $(TARGET)main_rm_cpp $(BUILDDIR)Model.o $(BUILDDIR)RulkovMap.o 

main_rm_c: $(SRCDIR)$(CF)main_rm_c.c rulkov_map.o $(INCL)$(CF)rulkov_map.h 
	$(CC) $(SRCDIR)$(CF)main_rm_c.c -o $(TARGET)main_rm_c $(BUILDDIR)rulkov_map.o $(LIB_MATH)


clean: clean_all
clean_all: clean_objects clean_runners
clean_objects:
	rm -f $(BUILDDIR)* 
clean_runners:
	rm -f $(TARGET)* 

clean_data:
	rm -rf $(DATA)* 