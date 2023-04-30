#ifndef __CG_TEST_CASE_H__
#define __CG_TEST_CASE_H__

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "../CG.h"

#define TEST_FILEPATH "C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/Tests/ExpectedImages/"

namespace CG {
	class Testcase
	{
	private: 
		std::vector<uint32_t> expected_pixels = std::vector<uint32_t>();
		bool passed = false;
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
