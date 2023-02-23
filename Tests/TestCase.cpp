#include <iomanip>
#include <iostream>
#include <string>

#include ".\TestCase.hpp"

// int TestCase::s_total = 0;
// int TestCase::s_passed = 0;

// TestCase::TestCase(const std::string &name) {

//   m_name = name;
//   m_result = false;
//   m_result = "";
//   s_total++;
//   m_current = s_total;
//   std::cout << ColorCodes::fg_DarkGrey;
//   std::cout << "RUNNING TEST CASE " << m_current << ".........................";
//   std::cout << std::endl;
// }

// bool TestCase::runTest(const CG_Image &base, CG_Image (*callback)(void)) {
//   CG_Image result = callback();
//   if (base.m_height != result.m_height) {
//     m_reason += "|\t HEIGHT does not match!\n";
//   }
//   if (base.m_width != result.m_width) {
//     m_reason += "|\t WIDTH does not match!\n";
//   }

//   if (m_reason.size() > 0) {
//     return m_result = false;
//   }

//   for (int y = 0; y < base.m_height; y++) {
//     for (int x = 0; x < base.m_width; x++) {
//       const CG_Pixel base_pixel = base.m_pixels[y * base.m_width + x];
//       const CG_Pixel result_pixel = result.m_pixels[y * result.m_width + x];
//       if (base_pixel != result_pixel) {
//         m_reason += "|\t CG_PIXEL at (" + std::to_string(x) + ", " +
//                     std::to_string(y) + ") does not match!\n";
//         m_result = false;
//       }
//     }
//   }
//   if (m_reason.size() == 0) {
//     m_result = true;
//   }
//   return m_result;
// }

// TestCase::~TestCase() {
//   std::string passed_failed;
//   if (m_result) {
//     s_passed++;
//     std::cout << ColorCodes::fg_Green;
//     passed_failed = "[PASSED!]";
//   } else {
//     std::cout << ColorCodes::fg_Red;
//     passed_failed = "[FAILED!]";
//   }
//   std::cout << "TEST CASE " << m_current << ": " << m_name;
//   std::cout << std::setw(CONSOLE_WIDTH - m_name.size()) << std::right
//             << passed_failed << std::endl;
//   if (m_reason.size() > 0) {
//     std::cout << m_reason << std::endl;
//   }
// }
// void TestCase::expectFailure() { m_result = !m_result; }

int TESTCASE::total_tests = 0;
int TESTCASE::pass_tests  = 0;
std::vector<std::string> TESTCASE::test_names   = std::vector<std::string>();
std::vector<bool>        TESTCASE::test_results = std::vector<bool>();
std::vector<std::string> TESTCASE::test_reasons = std::vector<std::string>();

void TESTCASE::appendTest(const std::string& name)
{
  test_names.push_back(name);
  test_results.push_back(false);
  test_reasons.push_back("");
}

void TESTCASE::createTest(const std::string& name)
{
  total_tests++;
  TESTCASE::appendTest(name);
}

void TESTCASE::summarizeCases()
{
  std::string passed_failed;
  for(int ct = 0; ct < total_tests; ct++) {
    // std::cout << ansi_code::foreground(CG::Color::darkgrey);
    if(test_results[ct] == true) {
      pass_tests++;
      std::cout << ansi_code::foreground(CG::Color::green);
      passed_failed = "[PASSED]!";
    } else {
      std::cout << ansi_code::foreground(CG::Color::red);
      passed_failed = "[FAILED]!";
    }
    
    std::cout << "TESTCASE " << std::to_string(ct + 1) << ": " << test_names[ct];
    std::cout << std::setw(CONSOLE_WIDTH - passed_failed.size()) << std::right << passed_failed << "\n";
    if(test_reasons[ct].size() > 0) {
      std::cout << test_reasons[ct] << std::endl;
    }
    std::string test_summary = std::to_string(pass_tests) + " / " + std::to_string(total_tests);

    std::cout << (pass_tests == total_tests) ? 
      ansi_code::foreground(CG::Color::green) : ansi_code::foreground(CG::Color::red);
    
    std::cout << "\nTOTAL TESTS PASSED:";
    std::cout << std::setw(CONSOLE_WIDTH - test_summary.size()) << std::right;
    std::cout << test_summary << std::endl;
    std::cout << ansi_code::reset;

  }
}

bool TESTCASE::assertEqual(const CG::Image &img1, const CG::Image &img2)
{
  bool result = true;

  if (img1.m_height != img2.m_height) {
    test_reasons[total_tests - 1] += "|\t HEIGHT does not match!\n";
  }
  if (img1.m_width != img2.m_width) {
    test_reasons[total_tests - 1] += "|\t WIDTH does not match!\n";
  }

  if (test_reasons[total_tests - 1].size() > 0) {
    return test_results[total_tests - 1] = false;
  }

  for (int y = 0; y < img1.m_height; y++) {
    for (int x = 0; x < img1.m_width; x++) {
      const CG::Pixel img1_pixel = img1.m_pixels[y * img1.m_width + x];
      const CG::Pixel img2_pixel = img2.m_pixels[y * img2.m_width + x];
      if (img1_pixel != img2_pixel) {
        test_reasons[total_tests - 1] += "|\t CG_PIXEL at (" + std::to_string(x) + ", " +
                    std::to_string(y) + ") does not match!\n";
        result = false;
      }
    }
  }
  return test_results[total_tests - 1] = result;
}

bool TESTCASE::assertNotEqual(const CG::Image &img1, const CG::Image &img2)
{
  bool r = assertEqual(img1, img2);
  test_reasons[total_tests - 1] = "";
  return test_results[total_tests - 1] = !r; 
}
