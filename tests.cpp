#include <iostream>

#include "CG/CG_Image.hpp"
#include "CG/ColorCodes.hpp"
#include "TestCase.hpp"

int main() {
  {
    CG_Image base_image(TEST_WIDTH, TEST_HEIGHT);
    TestCase test("Constructor");
    test.runTest(base_image, []() {
      CG_Image result(TEST_WIDTH, TEST_HEIGHT);
      return result;
    });
  }
  {
    CG_Image base_image(TEST_WIDTH, 5);
    TestCase test("Constructor with wrong height");
    test.runTest(base_image, []() {
      CG_Image result(TEST_WIDTH, TEST_HEIGHT);
      return result;
    });
    test.expectFailure();
  }

  if (TestCase::s_passed == TestCase::s_total) {
    std::cout << ColorCodes::fg_Green;
  } else {
    std::cout << ColorCodes::fg_Red;
  }
  std::cout << TestCase::s_passed << " out of " << TestCase::s_total
            << " PASSED!\n";
  std::cout << ColorCodes::Reset;
  return 0;
}