#ifndef __TEST_CASE_HPP__
#define __TEST_CASE_HPP__

#include "../CG/Image.hpp"
#include "../CG/Color.hpp"

#include <vector>

#define TEST_WIDTH 10
#define TEST_HEIGHT 10
#define CONSOLE_WIDTH 80

// class TestCase {
// private:
//   std::string m_name;
//   std::string m_reason;
//   bool m_result;
//   int m_current;
// public:
//   static int s_total;
//   static int s_passed;
//   TestCase(const std::string& name);
//   bool runTest(const CG_Image& base, CG_Image (*callback)(void));
//   ~TestCase();
//   void expectFailure();

// };

//  Testcase static class for CG::Image
  class TESTCASE {
  private:
    TESTCASE() {}
    static void appendTest(const std::string& name);

  public:
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