#ifndef HINDMARSHROSETEST_H
#define HINDMARSHROSETEST_H
#include "../HindmarshRose.h"
#include <cppunit/TestFixture.h>

class HindmarshRoseTest : public CppUnit::TestFixture
{

private:
    HindmarshRose *model;

public:
    void setUp();
    void tearDown();
    void runTest1();
    void runTest2();
};

#endif /* HINDMARSHROSETEST_H*/