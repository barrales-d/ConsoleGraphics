#include "CG.h"
#include "Tests/Testcase.h"
using namespace CG;

int main()
{
	Testcase test_rect = Testcase::declare_test("match_rect", "match_rect.expected.txt");
	Testcase test_circ = Testcase::declare_test("match_circ", "match_circ.expected.txt");
	Testcase test_elip = Testcase::declare_test("match_elip", "match_elip.expected.txt");
	Testcase test_line = Testcase::declare_test("match_line", "match_line.expected.txt");
	Testcase test_mult = Testcase::declare_test("match_mult_lines", "match_mult_lines.expected.txt");
	Testcase test_tran = Testcase::declare_test("test_transparency", "test_transparency.expected.txt");


	{
		test_rect.test_image.fill_background();
		test_rect.test_image.fill_rect(0, 0, 3, 2, Colors::red);
	}
	{
		test_circ.test_image.fill_background();
		test_circ.test_image.fill_circle(2, 2, 2, Colors::green);
	}
	{
		test_elip.test_image.fill_background();
		test_elip.test_image.fill_ellipse(2, 2, 2, 3, Colors::blue);
	}
	{
		test_line.test_image.fill_background();
		test_line.test_image.fill_line(0, 0, Testcase::size, Testcase::size, Colors::cyan);
	}
	{
		test_mult.test_image.fill_background();
		test_mult.test_image.fill_line(0, 0, 4, 4, Colors::lightblue);
		test_mult.test_image.fill_line(0, 0, 0, 5, Colors::lightblue);
		test_mult.test_image.fill_line(0, 0, 5, 0, Colors::lightblue);
		test_mult.test_image.fill_line(5, 5, 0, 0, Color(255, 50, 50, 120));
		test_mult.test_image.fill_line(5, 4, 1, 3, Color(50, 255, 50, 120));
	}
	{
		test_tran.test_image.fill_background();
		test_tran.test_image.fill_rect(0, 0, 2, 2, Color(0, 200, 240, 128));
		test_tran.test_image.fill_rect(1, 1, 3, 3, Color(120, 250, 50, 95));
	}
	Testcase::run_tests();

}