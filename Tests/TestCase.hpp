#ifndef __TEST_CASE_HPP__
#define __TEST_CASE_HPP__

#include "../CG/Image.hpp"
#include "../CG/Color.hpp"

#include <vector>
#include <optional>

#define CONSOLE_WIDTH 80

struct Test {
    std::string name;
    bool        result;
    std::string reason;
    std::optional<CG::Image>   image;
};

//  Testcase static class for CG::Image
class TESTCASE {
private:
    TESTCASE() {}
public:
    static bool print; 
    static int width;
    static int height;

    static int total_tests;
    static int pass_tests;

    static std::vector<Test> tests;

    static void createTest(const std::string& name);
    static bool assertEqual(const CG::Image &img1, const CG::Image &img2);
    static bool assertNotEqual(const CG::Image &img1, const CG::Image &img2);

    static void summarizeCases();

    template<class T>
    static bool assertAnyEqual(const T& a, const T& b);

    template<class T>
    static bool assertAnyNotEqual(const T& a, const T& b);
};

template<class T>
bool TESTCASE::assertAnyEqual(const T& a, const T& b)
{
    tests[total_tests - 1].reason = "";
    tests[total_tests - 1].image = CG::Image(0, 0);
    return tests[total_tests - 1].result = (a == b);
}

template<class T>
bool TESTCASE::assertAnyNotEqual(const T& a, const T& b)
{
    tests[total_tests - 1].reason = "";
    tests[total_tests - 1].image = CG::Image(0, 0);
    return tests[total_tests - 1].result = (a != b);
}
#endif // __TEST_CASE_HPP__