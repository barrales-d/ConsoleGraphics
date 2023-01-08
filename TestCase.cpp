#include "TestCase.hpp"

int TestCase::s_total = 0;
TestCase::TestCase(const std::string &name) {
  m_name = name;
  s_total++;
}
bool TestCase::getResults() { return result; }
void TestCase::setResult(const bool r) { result = r; }
