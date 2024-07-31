#ifndef MODELTEST_H
#define MODELTEST_H
#include "../Model.h"
#include <cppunit/TestFixture.h>

class ModelTest : public CppUnit::TestFixture
{

private:
  Model *model;

public:
  void setUp();
  void tearDown();
  void runTest1();
  void runTest2();
};

#endif /* MODELTEST_H*/