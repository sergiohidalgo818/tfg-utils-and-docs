#include "../../include/Model.h"
#include "../../include/tests/HindmarshRoseTest.h"
#include <cppunit/TestCase.h>
#include <filesystem>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

void HindmarshRoseTest::setUp()
{
  model = new HindmarshRose(0.001, "HindmarshRose_test", 3.0, 0.0021, 4);
}

void HindmarshRoseTest::tearDown()
{
    model->free();
    std::filesystem::remove("HindmarshRose_test");

}


void HindmarshRoseTest::runTest1()
{


}

void HindmarshRoseTest::runTest2()
{


}