#include "Testcase.h"

using namespace CG;

namespace {
	std::vector<Testcase*> testcases;
	int total_tests = 0;
	constexpr auto TEST_FILEPATH = "C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/CGTest/ExpectedImages/";
}

Testcase Testcase::declare_test(const std::string& name, const std::string& filename)
{
	Testcase test;
	test.name = name;
	test.file_name = filename;
	test.passed = true;
	test.test_image = Image(Testcase::size, Testcase::size);
	test.expected_pixels = std::vector<uint32_t>(Testcase::size * Testcase::size, 0);

	if (test.test_image.load_txt(TEST_FILEPATH + filename)) {
		//if expected.txt exists then you can save diff.txt if anything goes wrong
		test.save_diff = true;
		for (size_t y = 0; y < Testcase::size; y++) {
			for (size_t x = 0; x < Testcase::size; x++) {
				test.expected_pixels[y * Testcase::size + x] = test.test_image.m_pixels[y * Testcase::size + x].color();
			}
		}
	}
	
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
				auto expected_color = Color(test->expected_pixels[y * Testcase::size + x]);

				if (image_color != expected_color) {
					test->passed = false;

					if (test->save_diff)
						test->test_image.fill_point(x, y, DIFF_COLOR);
				}
			}
		}

		std::cout << "Testcase " << id + 1 << " " << test->name << ":";
		int txt_width = Math::abs(50 - test->name.size());
		for (int i = 0; i < txt_width; i++)
			std::cout << ".";

		if (test->passed || !test->save_diff) {
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

	if (this->save_diff) {
		output_file << Testcase::size << " " << Testcase::size << std::endl;
		for (size_t y = 0; y < Testcase::size; y++) {
			for (size_t x = 0; x < Testcase::size; x++) {
				auto expected_color = this->expected_pixels[y * Testcase::size + x];
				output_file << std::hex << expected_color << " ";
			}
			output_file << '\n';
		}
	}
	else {
		this->test_image.save_txt(TEST_FILEPATH + this->file_name);
	}

	output_file.close();

	if (!this->passed && this->save_diff) {
		std::string diff_filename = TEST_FILEPATH + this->name + ".diff.txt";
		this->test_image.save_txt(diff_filename);
	}
}

CG::Testcase::Testcase(Testcase&& t) noexcept
	: name(t.name), file_name(t.file_name), passed(t.passed) 
{
	this->test_image = std::move(t.test_image);
	this->expected_pixels = std::move(t.expected_pixels);
}