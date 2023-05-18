#include "Testcase.h"

using namespace CG;

namespace {
	std::vector<Testcase*> testcases;
	int total_tests = 0;
}

Testcase Testcase::declare_test(const std::string& name, const std::string& filename)
{
	Testcase test;
	test.name = name;
	test.file_name = filename;
	test.passed = true;
	test.test_image = Image(Testcase::size, Testcase::size);
	test.expected_pixels = std::vector<uint32_t>();

	std::fstream file(TEST_FILEPATH + filename, std::ios::in);
	uint32_t pixel = 0;
	while (file >> std::hex >> pixel)
		test.expected_pixels.push_back(pixel);
	file.close();
	//	set image to expected pixels (in main you edit the test_image and should be the same as expected_pixels)
	if(!test.expected_pixels.empty())
		test.test_image.fill_sprite(0, 0, test.expected_pixels, Testcase::size, Testcase::size);
		
	testcases.push_back(&test);
	total_tests++;
	return test;
}
void Testcase::run_tests()
{
	for (int id = 0; id < total_tests; id++) {
		auto& test = testcases[id];

		for (int y = 0; y < Testcase::size; y++) {
			for (int x = 0; x < Testcase::size; x++) {
				auto& image_color = test->test_image.m_pixels[(size_t)y * Testcase::size + x];
				auto expected_color = (test->expected_pixels.empty() ? Color(241, 75, 40) 
						: Color(test->expected_pixels[y * Testcase::size + x]));

				if (image_color != expected_color) {
					test->passed = false;

					if(!test->expected_pixels.empty())	//	only make diff if there exists expected_pixels already
						test->test_image.fill_point(x, y, Color(241, 75, 40));
				}
			}
		}

		std::cout << "Testcase " << id + 1 << " " << test->name << ":";
		auto txt_width = Math::abs(50 - test->name.size());
		for (int i = 0; i < txt_width; i++)
			std::cout << ".";

		if (test->passed || test->expected_pixels.empty()) {
			ansi::foreground(Colors::lightgreen);
			std::cout << "PASSED!\n";
		}
		else {
			ansi::foreground(Colors::lightred);
			std::cout << "FAILED!\n";
			test->test_image.show();
		}
		ansi::reset();

		test->save_test();
	}
}

void CG::Testcase::save_test()
{
	std::fstream output_file(TEST_FILEPATH + this->file_name, std::ios::out);

	if (this->expected_pixels.empty()) {
		this->test_image.save_txt(TEST_FILEPATH + this->file_name);
	}
	else {
		for (size_t y = 0; y < Testcase::size; y++) {
			for (size_t x = 0; x < Testcase::size; x++) {
				auto expected_color = this->expected_pixels[y * Testcase::size + x];
				output_file << std::hex << expected_color << " ";
			}
			output_file << '\n';
		}
	}

	output_file.close();

	if (!this->passed) {
		std::string diff_filename = TEST_FILEPATH + this->name + ".diff.txt";
		this->test_image.save_txt(diff_filename);
	}
}
