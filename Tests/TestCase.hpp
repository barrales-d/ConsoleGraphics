#ifndef __TEST_CASE_HPP__
#define __TEST_CASE_HPP__

#include "../CG/Image.hpp"
#include "../CG/Color.hpp"

#include <vector>

#define CONSOLE_WIDTH 80

//  Testcase static class for CG::Image
  class TESTCASE {
  private:
    TESTCASE() {}
  public:
    static int width;
    static int height;

    static int total_tests;
    static int pass_tests;

    static std::vector<std::string> test_names;
    static std::vector<bool> test_results;
    static std::vector<std::string> test_reasons;

    static void createTest(const std::string& name);
    static bool assertEqual(const CG::Image &img1, const CG::Image &img2);
    static bool assertNotEqual(const CG::Image &img1, const CG::Image &img2);

    static void summarizeCases();

  };

#endif // __TEST_CASE_HPP__