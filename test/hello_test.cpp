#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "lib.h"

// Первый блок тестов

class PositiveAndNegativeNumbers :public ::testing::TestWithParam< std::vector<int> > {};

TEST_P(PositiveAndNegativeNumbers, ProcessingPositiveAndNegativeNumbers) {
	std::vector<int> nums = GetParam();

	// arrange
	int num1 = nums[0],
	num2 = nums[1],

	// act
	res = nums[2];

	// assert;
	ASSERT_EQ(GCD(num1, num2), res);
}

INSTANTIATE_TEST_SUITE_P(
	NumbersWithoutZero,
	PositiveAndNegativeNumbers,
	::testing::Values(
		std::vector<int>{17, 51, 17},
		std::vector<int>{-17, 51, 17},
		std::vector<int>{17, -51, 17},
		std::vector<int>{-17, -51, 17},
		std::vector<int>{51, 17, 17},
		std::vector<int>{-51, 17, 17},
		std::vector<int>{51, -17, 17},
		std::vector<int>{-51, -17, 17},
		std::vector<int>{12, 18, 6},
		std::vector<int>{75, 10000, 25}
));

// Второй блок тестов

class ZeroInNumbers :public ::testing::TestWithParam<int> {};

TEST_P(ZeroInNumbers, ProcessingZero) {
	// arrange
	int num = GetParam();

	// act
	// Ну мы просто знаем, что функция должна вернуть logic_error

	// assert;
	ASSERT_THROW(GCD(0, num), std::logic_error);
	ASSERT_THROW(GCD(num, 0), std::logic_error);
}

INSTANTIATE_TEST_SUITE_P(
	NumbersWithZero,
	ZeroInNumbers,
	::testing::Values(
		-17, 51, 200
));