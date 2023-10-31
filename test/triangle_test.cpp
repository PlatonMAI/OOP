#include <triangle.h>
#include <triangleValidator.h>
#include <gtest/gtest.h>

using Points = std::vector<Point2D>;

class TriangleIncorrect : public ::testing::TestWithParam< Points > {};

TEST_P(TriangleIncorrect, Validation) {
	// arrange
    Points points = GetParam();

	// act
	// Ну мы просто знаем, что функция должна вернуть logic_error

	// assert
	ASSERT_THROW(Triangle::create(points), validator_error);
}

INSTANTIATE_TEST_SUITE_P(
	TriangleIncorrect_,
	TriangleIncorrect,
	::testing::Values(
        Points{{0, 0}, {0, 0}, {0, 0}, {0, 0}},
		Points{{0, 0}, {0, 0}, {0, 0}},
        Points{{0, 0}, {0, 1}, {0, 2}}
));



class Triangles : public ::testing::TestWithParam< Points > {};

TEST_P(Triangles, CalculateArea) {
    // arrange
    Points points = GetParam();
    Triangle triangle = Triangle::create(points);

    // act
    double
    expectedArea = 0.5,
    calculatedArea = double(triangle);

    // assert
    ASSERT_DOUBLE_EQ(expectedArea, calculatedArea);
}

INSTANTIATE_TEST_SUITE_P(
	TrianglesCorrect,
	Triangles,
	::testing::Values(
        Points{{0, 0}, {1, 0}, {0, 1}},
        Points{{0, 0}, {-1, 0}, {0, 1}},
        Points{{0, 0}, {-1, 0}, {0, -1}},
        Points{{0, 0}, {1, 0}, {0, -1}}
));



class TrianglesWithCenter : public ::testing::TestWithParam< Points > {};

TEST_P(TrianglesWithCenter, CalculateCenter) {
    // arrange
    Points points = GetParam();
    Point2D expectedCenter = points[3];
    points.pop_back();
    Triangle triangle = Triangle::create(points);

    // act
    Point2D calculatedCenter = triangle.get_center();

    // assert
    ASSERT_EQ(expectedCenter, calculatedCenter);
}

INSTANTIATE_TEST_SUITE_P(
	TrianglesWithCenter_,
	TrianglesWithCenter,
	::testing::Values(
        Points{{0, 0}, {1, 0}, {0, 1}, {1.0/3, 1.0/3}},
        Points{{0, 0}, {-1, 0}, {0, 1}, {-1.0/3, 1.0/3}},
        Points{{0, 0}, {-1, 0}, {0, -1}, {-1.0/3, -1.0/3}},
        Points{{0, 0}, {1, 0}, {0, -1}, {1.0/3, -1.0/3}}
));



// TEST(Triangles, CheckEquality) {
//     // arrange
//     Points
//     tri1{{11, 32}, {-38, 20.323}, {-21.332, 323}},
//     tri2{{11, 32}, {-38, 20.323}, {-21.332, 323}},
//     tri3{{0, 0}, {-1, 0}, {0, -1}};
//     Triangle
//     triangle1 = Triangle::create(tri1),
//     triangle2 = Triangle::create(tri2),
//     triangle3 = Triangle::create(tri3);

//     // act
//     bool
//     expectedRes1 = true,
//     expectedRes2 = false,
//     res1 = (triangle1 == triangle2),
//     res2 = (triangle1 == triangle3);

//     // assert
//     ASSERT_EQ(res1, expectedRes1);
//     ASSERT_EQ(res2, expectedRes2);
// }