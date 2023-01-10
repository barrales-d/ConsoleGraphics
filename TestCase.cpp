#include <iostream>
#include <string>

#include "TestCase.hpp"

int TestCase::s_total = 0;
int TestCase::s_passed = 0;

TestCase::TestCase(const std::string &name) {

  m_name = name;
  m_result = false;
  m_result = "";
  s_total++;
  m_current = s_total;
  std::cout << ColorCodes::fg_DarkGrey;
  std::cout << "RUNNING TEST CASE " << m_current << "............" << std::endl;
}

void TestCase::runTest(const CG_Image &base, CG_Image (*callback)(void)) {
  CG_Image result = callback();
  if (base.m_height != result.m_height) {
    m_reason += "|\t HEIGHT does not match!\n";
  }
  if (base.m_width != result.m_width) {
    m_reason += "|\t WIDTH does not match!\n";
  }
  if (base.m_max_width != result.m_max_width) {
    m_reason += "|\t MAX_WIDTH does not match!\n";
  }

  for (int y = 0; y < base.m_height; y++) {
    for (int x = 0; x < base.m_max_width; x++) {
      const CG_Pixel base_pixel = base.m_pixels[y * base.m_max_width + x];
      const CG_Pixel result_pixel = result.m_pixels[y * result.m_max_width + x];
      if (base_pixel != result_pixel) {
        m_reason += "\t" + m_name + " CG_PIXEL at (" + std::to_string(x) +
                    ", " + std::to_string(y) + ") does not match!\n";
      }
    }
  }

  if (m_reason.size() > 0) {
    m_result = false;
  } else {
    m_result = true;
  }
}

TestCase::~TestCase() {
  std::string passed_failed;
  if (m_result) {
    s_passed++;
    std::cout << ColorCodes::fg_Green;
    passed_failed = "               [PASSED!]\n";
  } else {
    std::cout << ColorCodes::fg_Red;
    passed_failed = "               [FAILED!]\n";
  }
  std::cout << "TEST CASE " << m_current << ": " << m_name;
  std::cout << passed_failed;
  if (m_result == false) {
    std::cout << m_reason << std::endl;
  }
}
void TestCase::expectFailure() { m_result = !m_result; }