#include "../../../include/cpp/tests/HindmarshRoseTest.h"

#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

int main()
{
  CppUnit::TextUi::TestRunner runner;
  CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();

  runner.addTest(new CppUnit::TestCaller<HindmarshRoseTest>(
      "testEquality",
      &HindmarshRoseTest::runTest1));

  runner.addTest(new CppUnit::TestCaller<HindmarshRoseTest>(
      "testEquality",
      &HindmarshRoseTest::runTest2));


  bool wasSuccessful = runner.run();
  return !wasSuccessful;
}