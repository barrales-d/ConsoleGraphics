#include <iomanip>
#include <iostream>
#include <string>

#include ".\TestCase.hpp"


int TESTCASE::width = 10;
int TESTCASE::height = 10;

int TESTCASE::total_tests = 0;
int TESTCASE::pass_tests  = 0;
std::vector<std::string> TESTCASE::test_names   = std::vector<std::string>();
std::vector<bool>        TESTCASE::test_results = std::vector<bool>();
std::vector<std::string> TESTCASE::test_reasons = std::vector<std::string>();

void TESTCASE::createTest(const std::string& name)
{
  total_tests++;
  test_names.push_back(name);
  test_results.push_back(false);
  test_reasons.push_back("");
}

void TESTCASE::summarizeCases()
{
  std::string passed_failed;
  for(int ct = 0; ct < total_tests; ct++) {
    // std::cout << ansi_code::foreground(CG::Color::darkgrey);
    if(test_results[ct] == true) {
      pass_tests++;
      std::cout << ansi_code::foreground(CG::Color::lightgreen);
      passed_failed = "[PASSED]";
    } else {
      std::cout << ansi_code::foreground(CG::Color::lightred);
      passed_failed = "[FAILED]";
    }
    
    std::cout << "TESTCASE " << std::to_string(ct + 1) << ": " << test_names[ct];
    std::cout << std::setw(CONSOLE_WIDTH - test_names[ct].size() + passed_failed.size());
    std::cout << std::right << passed_failed << "\n";

    if(test_reasons[ct].size() > 0) {
      std::cout << test_reasons[ct] << std::endl;
    }
  }
  std::string summary_output = std::to_string(pass_tests) + " / " 
    + std::to_string(total_tests) + " Tests";

  if(pass_tests == total_tests)
    std::cout << ansi_code::foreground(CG::Color::lightgreen);
  else
    std::cout << ansi_code::foreground(CG::Color::lightred);
  
  std::cout << "\nTOTAL TESTS PASSED:\n" << std::setw(CONSOLE_WIDTH + summary_output.size()) << std::right;
  std::cout << summary_output << "\n";
  std::cout << ansi_code::reset;

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
