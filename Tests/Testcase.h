#ifndef __CG_TEST_CASE_H__
#define __CG_TEST_CASE_H__

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "../CG.h"

constexpr auto TEST_FILEPATH = "C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/Tests/ExpectedImages/";

#define DIFF_COLOR Color(250, 10, 10)

namespace CG {
	class Testcase
	{
	private: 
		std::vector<uint32_t> expected_pixels = std::vector<uint32_t>();
		bool passed = false;
		bool save_diff = false;
		void save_test();
	public:
		CG::Image test_image = Image();
		std::string name = "";
		std::string file_name = "";
		
		static Testcase declare_test(const std::string& name, const std::string& filename);
		static void run_tests();

		static constexpr int size = 5;
	};
}

#endif //	__CG_TEST_CASE_H__
