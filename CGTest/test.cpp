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
		img.fill_point(0, 0, Colors::red);
		Image copy = std::move(img);

		ASSERT_EQ(Colors::red, copy.get(0, 0));
		
	}

	class CGImageTest : public testing::Test {
	protected:
		Image* m_img;
		static inline int SIZE = 10;
		Color m_testColor;
		Color m_backgroundColor = Colors::black;

		virtual void SetUp() override {
			m_img = new Image(SIZE, SIZE);
			m_img->fill_background(m_backgroundColor);
			m_testColor = Color(0xFF90502E);
		}

		virtual void TearDown() override {
			if (::testing::Test::HasFailure()) {
				m_img->show();
			}
			delete m_img;
			m_img = nullptr;
		}
	};

	TEST_F(CGImageTest, FillPoint)
	{
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

	TEST_F(CGImageTest, FillRectOutOfBounds)
	{
		m_img->fill_rect(-5, -5, 3, 3, m_testColor);
		ASSERT_EQ(m_backgroundColor, m_img->get(0, 0));
		m_img->fill_rect(SIZE, SIZE, 3, 3, m_testColor);
		ASSERT_EQ(m_backgroundColor, m_img->get(SIZE - 1, SIZE - 1));
	}

	TEST_F(CGImageTest, FillRectInBounds)
	{
		m_img->fill_rect(0, 0, 3, 3, m_testColor);
		ASSERT_EQ(m_testColor, m_img->get(3, 3));
		m_img->fill_rect(SIZE - 3, SIZE - 3, 3, 3, m_testColor);
		ASSERT_EQ(m_testColor, m_img->get(SIZE - 1, SIZE - 1));
	}

	TEST_F(CGImageTest, FillCircleOutofBounds)
	{
		m_img->fill_circle(-5, -5, 2, m_testColor);
		ASSERT_EQ(m_backgroundColor, m_img->get(0, 0));
		m_img->fill_circle(SIZE + 3, SIZE + 3, 3, m_testColor);
		ASSERT_EQ(m_backgroundColor, m_img->get(SIZE - 1, SIZE - 1));
	}

	TEST_F(CGImageTest, FillCircleInBounds)
	{
		m_img->fill_circle(SIZE / 2, SIZE / 2, 4, m_testColor);
		ASSERT_EQ(m_testColor, m_img->get(SIZE / 2, SIZE / 2));
	}

	TEST_F(CGImageTest, FillTriangleOutofBounds)
	{
		m_img->fill_triangle(-3, -3, 0, -3, -3, 0, m_testColor);
		ASSERT_EQ(m_backgroundColor, m_img->get(0, 0));

		m_img->fill_triangle(SIZE - 3, -1, SIZE, -1, SIZE - 3, -3, m_testColor);
		ASSERT_EQ(m_backgroundColor, m_img->get(SIZE - 1, 0));

	}

	TEST_F(CGImageTest, FillTriangleInBounds)
	{
		m_img->fill_triangle(0, 0, SIZE - 1, 0, SIZE - 1, 3, m_testColor);
		ASSERT_EQ(m_testColor, m_img->get(SIZE - 1, 3));
	}

	TEST_F(CGImageTest, FillTriangleTwoColors)
	{
		Vec2 p1(0, SIZE - 2);
		Vec2 p2(SIZE / 2 - 1, 0);
		Vec2 p3(SIZE - 2, SIZE - 2);
		m_img->fill_triangle(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, m_testColor, Colors::red);
		ASSERT_NE(m_backgroundColor, m_img->get(4, 4));
		ASSERT_EQ(m_testColor, m_img->get(p1.x, p1.y));
		ASSERT_EQ(Colors::red, m_img->get(p2.x, p2.y));
	}

	TEST_F(CGImageTest, FillTriangleThreeColors)
	{
		Vec2 p1(0, SIZE - 2);
		Vec2 p2(SIZE / 2 - 1, 0);
		Vec2 p3(SIZE - 2, SIZE - 2);
		m_img->fill_triangle(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, m_testColor, Colors::red, Colors::cyan);
		ASSERT_NE(m_backgroundColor, m_img->get(4, 4));
		ASSERT_EQ(m_testColor, m_img->get(p1.x, p1.y));
		ASSERT_EQ(Colors::red, m_img->get(p2.x, p2.y));
		ASSERT_EQ(Colors::cyan, m_img->get(p3.x, p3.y));
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