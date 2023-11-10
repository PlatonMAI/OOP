#include <../src/rectangle.cpp>
#include <../src/rectangleValidator.cpp>
#include <gtest/gtest.h>

using Points = std::vector<Point2D<double>>;

class RectangleIncorrect : public ::testing::TestWithParam< Points > {};

TEST_P(RectangleIncorrect, Validation) {
	// arrange
    Points points = GetParam();

	// act
	// Ну мы просто знаем, что функция должна вернуть logic_error

	// assert
	ASSERT_THROW(Rectangle<double>::create(points), validator_error);
}

INSTANTIATE_TEST_SUITE_P(
	RectangleIncorrect_,
	RectangleIncorrect,
	::testing::Values(
        Points{{0, 0}, {0, 0}}, // Мало точек
		Points{{0, 0}, {0, 0}, {322, 23}, {22.2, -23}}, // Две одинаковые
        Points{{0, 0}, {0, 1}, {2, 0}, {1, 1}}, // Нет прямого угла
        Points{{0, 0}, {0, 1}, {0, 2}, {1, 1}} // Три точки лежат на одной прямой
));



class Rectangles : public ::testing::TestWithParam< Points > {};

TEST_P(Rectangles, CalculateArea) {
    // arrange
    Points points = GetParam();
    Rectangle<double> rectangle = Rectangle<double>::create(points);

    // act
    double
    expectedArea = 4,
    calculatedArea = double(rectangle);

    // assert
    ASSERT_DOUBLE_EQ(expectedArea, calculatedArea);
}

INSTANTIATE_TEST_SUITE_P(
	RectanglesCorrect,
	Rectangles,
	::testing::Values(
        Points{{1, 1}, {3, 1}, {1, 3}, {3, 3}},
        Points{{-1, 1}, {-3, 1}, {-1, 3}, {-3, 3}},
        Points{{-1, -1}, {-3, -1}, {-1, -3}, {-3, -3}},
        Points{{1, -1}, {3, -1}, {1, -3}, {3, -3}}
));



class RectanglesWithCenter : public ::testing::TestWithParam< Points > {};

TEST_P(RectanglesWithCenter, CalculateCenter) {
    // arrange
    Points points = GetParam();
    Point2D<double> expectedCenter = points[4];
    points.pop_back();
    Rectangle<double> rectangle = Rectangle<double>::create(points);

    // act
    Point2D<double> calculatedCenter = rectangle.get_center();

    // assert
    ASSERT_EQ(expectedCenter, calculatedCenter);
}

INSTANTIATE_TEST_SUITE_P(
	RectanglesWithCenter_,
	RectanglesWithCenter,
	::testing::Values(
        Points{{1, 1}, {3, 1}, {1, 3}, {3, 3}, {2, 2}},
        Points{{-1, 1}, {-3, 1}, {-1, 3}, {-3, 3}, {-2, 2}},
        Points{{-1, -1}, {-3, -1}, {-1, -3}, {-3, -3}, {-2, -2}},
        Points{{1, -1}, {3, -1}, {1, -3}, {3, -3}, {2, -2}}
));



// TEST(Rectangles, CheckEquality) {
//     // arrange
//     Points
//     tri1{{11, 32}, {-38, 20.323}, {-21.332, 323}},
//     tri2{{11, 32}, {-38, 20.323}, {-21.332, 323}},
//     tri3{{0, 0}, {-1, 0}, {0, -1}};
//     Rectangle
//     rectangle1 = Rectangle::create(tri1),
//     rectangle2 = Rectangle::create(tri2),
//     rectangle3 = Rectangle::create(tri3);

//     // act
//     bool
//     expectedRes1 = true,
//     expectedRes2 = false,
//     res1 = (rectangle1 == rectangle2),
//     res2 = (rectangle1 == rectangle3);

//     // assert
//     ASSERT_EQ(res1, expectedRes1);
//     ASSERT_EQ(res2, expectedRes2);
// }