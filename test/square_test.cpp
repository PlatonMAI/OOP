#include <square.h>
#include <squareValidator.h>
#include <gtest/gtest.h>

using Points = std::vector<Point2D>;

class SquareIncorrect : public ::testing::TestWithParam< Points > {};

TEST_P(SquareIncorrect, Validation) {
	// arrange
    Points points = GetParam();

	// act
	// Ну мы просто знаем, что функция должна вернуть logic_error

	// assert
	ASSERT_THROW(Square::create(points), validator_error);
}

INSTANTIATE_TEST_SUITE_P(
	SquareIncorrect_,
	SquareIncorrect,
	::testing::Values(
        Points{{0, 0}, {0, 0}}, // Мало точек
		Points{{0, 0}, {0, 0}, {322, 23}, {22.2, -23}}, // Две одинаковые
        Points{{0, 0}, {0, 1}, {2, 0}, {1, 1}}, // Нет прямого угла
        Points{{0, 0}, {0, 1}, {0, 2}, {1, 1}}, // Три точки лежат на одной прямой
        Points{{2, 0}, {0, 0}, {2, 1}, {0, 1}} // Не равны стороны
));



class Squares : public ::testing::TestWithParam< Points > {};

TEST_P(Squares, CalculateArea) {
    // arrange
    Points points = GetParam();
    Square square = Square::create(points);

    // act
    double
    expectedArea = 4,
    calculatedArea = double(square);

    // assert
    ASSERT_DOUBLE_EQ(expectedArea, calculatedArea);
}

INSTANTIATE_TEST_SUITE_P(
	SquaresCorrect,
	Squares,
	::testing::Values(
        Points{{1, 1}, {3, 1}, {1, 3}, {3, 3}},
        Points{{-1, 1}, {-3, 1}, {-1, 3}, {-3, 3}},
        Points{{-1, -1}, {-3, -1}, {-1, -3}, {-3, -3}},
        Points{{1, -1}, {3, -1}, {1, -3}, {3, -3}}
));



class SquaresWithCenter : public ::testing::TestWithParam< Points > {};

TEST_P(SquaresWithCenter, CalculateCenter) {
    // arrange
    Points points = GetParam();
    Point2D expectedCenter = points[4];
    points.pop_back();
    Square square = Square::create(points);

    // act
    Point2D calculatedCenter = square.get_center();

    // assert
    ASSERT_EQ(expectedCenter, calculatedCenter);
}

INSTANTIATE_TEST_SUITE_P(
	SquaresWithCenter_,
	SquaresWithCenter,
	::testing::Values(
        Points{{1, 1}, {3, 1}, {1, 3}, {3, 3}, {2, 2}},
        Points{{-1, 1}, {-3, 1}, {-1, 3}, {-3, 3}, {-2, 2}},
        Points{{-1, -1}, {-3, -1}, {-1, -3}, {-3, -3}, {-2, -2}},
        Points{{1, -1}, {3, -1}, {1, -3}, {3, -3}, {2, -2}}
));



// TEST(Squares, CheckEquality) {
//     // arrange
//     Points
//     tri1{{11, 32}, {-38, 20.323}, {-21.332, 323}},
//     tri2{{11, 32}, {-38, 20.323}, {-21.332, 323}},
//     tri3{{0, 0}, {-1, 0}, {0, -1}};
//     Square
//     square1 = Square::create(tri1),
//     square2 = Square::create(tri2),
//     square3 = Square::create(tri3);

//     // act
//     bool
//     expectedRes1 = true,
//     expectedRes2 = false,
//     res1 = (square1 == square2),
//     res2 = (square1 == square3);

//     // assert
//     ASSERT_EQ(res1, expectedRes1);
//     ASSERT_EQ(res2, expectedRes2);
// }