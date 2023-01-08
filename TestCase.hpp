#ifndef __TEST_CASE_HPP__
#define __TEST_CASE_HPP__

#include "./CG/CG_Image.hpp"
#include "./CG/ColorCodes.hpp"

class TestCase{
private:
std::string m_name;
bool result;

public:
  static int s_total;
  TestCase(const std::string& name);
  bool getResults(); 
  void setResult(const bool r);
};

#endif // __TEST_CASE_HPP__