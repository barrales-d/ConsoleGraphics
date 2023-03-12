#include <iomanip>
#include <iostream>
#include <string>

#include "./TestCase.hpp"


int TESTCASE::width = 10;
int TESTCASE::height = 10;

int TESTCASE::total_tests = 0;
int TESTCASE::pass_tests  = 0;
bool TESTCASE::print  = false;

std::vector<Test> TESTCASE::tests = std::vector<Test>();

void TESTCASE::createTest(const std::string& name)
{
    Test t;
    t.name = name;
    t.result = true;
    t.reason = "";
    tests.push_back(t);

    total_tests++;
}

void TESTCASE::summarizeCases()
{
    std::string passed_failed;
    for(int ct = 0; ct < total_tests; ct++) {
        // std::cout << ansi_code::foreground(CG::Color::darkgrey);
        if(tests[ct].result == true) {
            pass_tests++;
            std::cout << ansi_code::foreground(CG::Color::lightgreen);
            passed_failed = "[PASSED]";
        } else {
            std::cout << ansi_code::foreground(CG::Color::lightred);
            passed_failed = "[FAILED]";
        }

        if(tests[ct].reason.size() > 0) {
            std::cout << std::endl << tests[ct].reason;
        }

        std::cout << "TESTCASE " << std::to_string(ct + 1) << ": " << tests[ct].name;
        std::cout << std::setw(CONSOLE_WIDTH - tests[ct].name.size() - passed_failed.size() + 10);
        std::cout << std::right << passed_failed << "\n";
        tests[ct].image.show();
    }
    std::string summary_output = std::to_string(pass_tests) + " / " +
                                std::to_string(total_tests) + " Tests";

    if(pass_tests == total_tests) std::cout << ansi_code::foreground(CG::Color::lightgreen);
    else std::cout << ansi_code::foreground(CG::Color::lightred);

    std::cout << "\nTOTAL TESTS PASSED:\n" << std::setw(CONSOLE_WIDTH - summary_output.size()) << std::right;
    std::cout << summary_output << "\n";
    std::cout << ansi_code::reset;
}

bool TESTCASE::assertEqual(const CG::Image &img1, const CG::Image &img2)
{
    bool result = true;

    if (img1.m_height != img2.m_height) {
    tests[total_tests - 1].reason += "|\t HEIGHT does not match!\n";
    }

    if (img1.m_width != img2.m_width) {
    tests[total_tests - 1].reason += "|\t WIDTH does not match!\n";
    }

    if (tests[total_tests - 1].reason.size() > 0) {
        tests[total_tests - 1].image = CG::Image(0, 0);
        return tests[total_tests - 1].result = false;
    }

    for (int y = 0; y < img1.m_height; y++) {
        for (int x = 0; x < img1.m_width; x++) {
            const CG::Pixel img1_pixel = img1.m_pixels[y * img1.m_width + x];
            const CG::Pixel img2_pixel = img2.m_pixels[y * img2.m_width + x];
            if (img1_pixel != img2_pixel) {
                tests[total_tests - 1].reason += "|\t CG::PIXEL at (" + std::to_string(x) + ", " +
                std::to_string(y) + ") does not match!\n";
                result = false;
            }
        }
    }
    if(TESTCASE::print)
        tests[total_tests - 1].image = CG::Image::combine_image(img1, img2, CG::Color(0xFF12BB));
    else 
        tests[total_tests - 1].image = CG::Image(0, 0);

    return tests[total_tests - 1].result = result;
}

bool TESTCASE::assertNotEqual(const CG::Image &img1, const CG::Image &img2)
{
    bool r = assertEqual(img1, img2);
    tests[total_tests - 1].reason = "";
    
    return tests[total_tests - 1].result = !r;
}