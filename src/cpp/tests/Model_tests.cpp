#include "../../../include/cpp/tests/ModelTest.h"

#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

int main()
{
  CppUnit::TextUi::TestRunner runner;
  CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();

  runner.addTest(new CppUnit::TestCaller<ModelTest>(
      "testEquality",
      &ModelTest::runTest1));

  runner.addTest(new CppUnit::TestCaller<ModelTest>(
      "testEquality",
      &ModelTest::runTest2));


  bool wasSuccessful = runner.run();
  return !wasSuccessful;
}