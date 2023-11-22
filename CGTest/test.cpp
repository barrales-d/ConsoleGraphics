#include <CG.h>
#include <gtest/gtest.h>
using namespace CG;

namespace {

	TEST(CGColor, Constructors)
	{
		Color color(0xFF0000FF);
		ASSERT_EQ(Colors::red, color);
		Color colorFromInt = 0xFFFF0000;
		ASSERT_EQ(Colors::blue, colorFromInt);
		Color colorFromVec(Vec4f(1.0f, 1.0f, 1.0f, 1.0f));
		ASSERT_EQ(Colors::white, colorFromVec);

		Color alphaColor(255, 0, 0, 100);
		ASSERT_NE(Colors::red, alphaColor);
	}

	TEST(CGColor, AlphaBlending)
	{
		Color backgroundColor(0xFF0000FF);
		Color foregroundColor = 0xFFFF0000;

		Color colorResult = backgroundColor + foregroundColor;
		ASSERT_NE(backgroundColor, colorResult);
		ASSERT_EQ(foregroundColor, colorResult);

		backgroundColor = Color(255, 0, 0, 100);
		foregroundColor = Color(255, 0, 255, 200);
		colorResult = backgroundColor + foregroundColor;
		ASSERT_NE(backgroundColor, colorResult);
		ASSERT_NE(foregroundColor, colorResult);
	}

	TEST(CGColor, Lerp)
	{
		ASSERT_EQ(Colors::red, Color::lerp_colors(0, Colors::red, Colors::blue));
		ASSERT_EQ(Colors::blue, Color::lerp_colors(1, Colors::red, Colors::blue));
		ASSERT_EQ(Color(0xFF7F007F), Color::lerp_colors(0.5f, Colors::red, Colors::blue));
	}
}// end of CG::Color Tests

namespace {
	constexpr int IMG_SIZE = 10;
	TEST(CGImage, BasicConstructor)
	{
		Image img(IMG_SIZE, IMG_SIZE);

		ASSERT_EQ(IMG_SIZE, img.get_width());
		ASSERT_EQ(IMG_SIZE, img.get_height());
	}

	TEST(CGImage, MoveConstructor)
	{
		Image img(IMG_SIZE, IMG_SIZE);

		Image copy = std::move(img);

		ASSERT_EQ(IMG_SIZE, copy.get_width());
		
	}

	class CGImageTest : public testing::Test {
	protected:
		Image* m_img;
		static inline int SIZE = 10;
		Color m_testColor;

		virtual void SetUp() override {
			m_img = new Image(SIZE, SIZE);
			m_testColor = Color(0xFF90502e);
		}

		virtual void TearDown() override {
			if (::testing::Test::HasFailure()) {
				m_img->show();
			}
			delete m_img;
			m_img = nullptr;
		}
	};

	TEST_F(CGImageTest, FillPoint) {
		Vec2 p1 = { 0, 0 };
		Vec2 p2 = { SIZE - 1, SIZE - 1 };
		Vec2 p3 = { SIZE / 2, SIZE / 2 };

		m_img->fill_point(p1.x, p1.y, m_testColor);
		m_img->fill_point(p2.x, p2.y, m_testColor);
		m_img->fill_point(p3.x, p3.y, m_testColor);

		auto pointColor = m_img->get(p1.x, p1.y);
		ASSERT_EQ(m_testColor, pointColor);

		pointColor = m_img->get(p2.x, p2.y);
		ASSERT_EQ(m_testColor, pointColor);

		pointColor = m_img->get(p3.x, p3.y);
		ASSERT_EQ(m_testColor, pointColor);
	}

}// end of CG::Image Tests

int main()
{
	testing::InitGoogleTest();
	RUN_ALL_TESTS();
}
#if 0
	Testcase test_clamp_rect = Testcase::declare_test("clamp_rect", "clamp_rect.expected.txt");
	Testcase test_rect		 = Testcase::declare_test("match_rect", "match_rect.expected.txt");
	{
		test_clamp_rect.test_image.fill_background();
		//	left clamp
		test_clamp_rect.test_image.fill_rect(-2, 1, 3, 3, Colors::blue);
		//	right clamp
		test_clamp_rect.test_image.fill_rect(4, 1, 3, 3, Colors::green);
		//	top clamp
		test_clamp_rect.test_image.fill_rect(1, -2, 3, 3, Colors::red);
		//	bottom clamp
		test_clamp_rect.test_image.fill_rect(1, 4, 3, 3, Colors::lightpurple);
	}
	Testcase test_circ		 = Testcase::declare_test("match_circ", "match_circ.expected.txt");
	Testcase test_elip		 = Testcase::declare_test("match_elip", "match_elip.expected.txt");
	Testcase test_line		 = Testcase::declare_test("match_line", "match_line.expected.txt");
	Testcase test_mult		 = Testcase::declare_test("match_mult_lines", "match_mult_lines.expected.txt");
	Testcase test_tran		 = Testcase::declare_test("test_transparency", "test_transparency.expected.txt");
	Testcase test_rectline	 = Testcase::declare_test("match_rectline", "match_rectline.expected.txt");


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
		test_mult.test_image.fill_line(0, 0, 3, 3, Colors::lightblue);
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

	{
		test_rectline.test_image.fill_background();
		test_rectline.test_image.fill_rect(0, 0, 5, 5, Colors::black);
		test_rectline.test_image.fill_rect_line(0, 0, 5, 5, Colors::lightred);
	}

	Testcase::run_tests();
}
#endif