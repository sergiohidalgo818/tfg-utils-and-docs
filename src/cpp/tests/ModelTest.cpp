#include "../../../include/cpp/Model.h"
#include "../../../include/cpp/tests/ModelTest.h"
#include <cppunit/TestCase.h>
#include <filesystem>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

void ModelTest::setUp()
{
  model = new Model(0.001, "Model_test");
}

void ModelTest::tearDown()
{
  model->free();
  std::filesystem::remove("Model_test");
}

void ModelTest::runTest1()
{
  CPPUNIT_ASSERT(model->outfile.is_open());
}

void ModelTest::runTest2()
{
  std::stringstream buff;
  std::string aux;
  std::ifstream file;

  file.open("Model_test");

  model->outfile << "test";

  buff << file.rdbuf();

  aux = buff.str();

  CPPUNIT_ASSERT(aux.compare("test"));
}
