#ifndef __TEST_CASE_HPP__
#define __TEST_CASE_HPP__

#include "./CG/CG_Image.hpp"
#include "./CG/ColorCodes.hpp"

#define TEST_WIDTH 10
#define TEST_HEIGHT 10
#define CONSOLE_WIDTH 80

class TestCase {
private:
  std::string m_name;
  std::string m_reason;
  bool m_result;
  int m_current;
public:
  static int s_total;
  static int s_passed;
  TestCase(const std::string& name);
  void runTest(const CG_Image& base, CG_Image (*callback)(void));
  ~TestCase();
  void expectFailure();

};
#endif // __TEST_CASE_HPP__