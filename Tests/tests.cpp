#include <iostream>

#include "../CG/Image.hpp"
#include "../CG/Color.hpp"
#include "./TestCase.hpp"

int main() {
  {
    CG::TESTCASE::createTest("Constructor");
    CG::Image base_image(TEST_WIDTH, TEST_HEIGHT);
    CG::Image new_image(TEST_WIDTH, TEST_HEIGHT);

    CG::TESTCASE::assertEqual(base_image, new_image);
    
    CG::TESTCASE::summarizeCases();

  }
  // {
  //   TestCase test("Constructor with wrong height");

  //   CG_Image base_image(TEST_WIDTH, TEST_HEIGHT);
  //   test.runTest(base_image, []() {
  //     CG_Image result(TEST_WIDTH, 5);
  //     return result;
  //   });
  //   test.expectFailure();
  // }
  // {
  //   TestCase test("Constructor with wrong width");

  //   CG_Image base_image(TEST_WIDTH, TEST_HEIGHT);
  //   test.runTest(base_image, []() {
  //     CG_Image result(3, TEST_HEIGHT);
  //     return result;
  //   });
  //   test.expectFailure();
  // }
  // {
  //   TestCase test("Constructor default fill background");

  //   CG_Image base_image(TEST_WIDTH, TEST_HEIGHT);
  //   base_image.fill_background(ColorCodes::bg_DarkGrey);

  //   test.runTest(base_image, []() {
  //     CG_Image result(TEST_WIDTH, TEST_HEIGHT);
  //     return result;
  //   });
  // }
  // {
  //   TestCase test("CG_Image::fillbackground(Blue)");

  //   CG_Image base_image(TEST_WIDTH, TEST_HEIGHT);
  //   base_image.fill_background(ColorCodes::bg_Blue);
  //   test.runTest(base_image, []() {
  //     CG_Image result(TEST_WIDTH, TEST_HEIGHT);
  //     result.fill_background(ColorCodes::bg_Blue);
  //     return result;
  //   });
  // }

  // {
  //   TestCase test("CG_Image::fill_rect() matching");

  //   CG_Image base_image(TEST_WIDTH, TEST_HEIGHT);
  //   int wd = TEST_WIDTH / 5;
  //   int x = TEST_WIDTH / 2 - wd;
  //   int ht = TEST_WIDTH / 5;
  //   int y = TEST_HEIGHT / 2 - ht;
  //   base_image.fill_rect(x, y, wd, ht, ColorCodes::bg_Red);

  //   test.runTest(base_image, []() {
  //     CG_Image result(TEST_WIDTH, TEST_HEIGHT);
  //     int wd = TEST_WIDTH / 5;
  //     int x = TEST_WIDTH / 2 - wd;
  //     int ht = TEST_WIDTH / 5;
  //     int y = TEST_HEIGHT / 2 - ht;
  //     result.fill_rect(x, y, wd, ht, ColorCodes::bg_Red);
  //     return result;
  //   });
  // }
  // {
  //   TestCase test("CG_Image::fill_rect() Don't Match");

  //   CG_Image base_image(TEST_WIDTH, TEST_HEIGHT);
  //   int wd = TEST_WIDTH / 3;
  //   int x = TEST_WIDTH / 2 - wd;
  //   int ht = TEST_WIDTH / 2;
  //   int y = TEST_HEIGHT / 2 - ht;
  //   base_image.fill_rect(x, y, wd, ht, ColorCodes::bg_Red);

  //   test.runTest(base_image, []() {
  //     CG_Image result(TEST_WIDTH, TEST_HEIGHT);
  //     int wd = TEST_WIDTH / 5;
  //     int x = TEST_WIDTH / 2 - wd;
  //     int ht = TEST_WIDTH / 5;
  //     int y = TEST_HEIGHT / 2 - ht;
  //     result.fill_rect(x, y, wd, ht, ColorCodes::bg_Red);
  //     return result;
  //   });
  //   test.expectFailure();
  // }

  // if (TestCase::s_passed == TestCase::s_total) {
  //   std::cout << ColorCodes::fg_Green;
  // } else {
  //   std::cout << ColorCodes::fg_Red;
  // }
  // std::cout << TestCase::s_passed << " out of " << TestCase::s_total
  //           << " PASSED!\n";
  // std::cout << ColorCodes::Reset;
  return 0;
}