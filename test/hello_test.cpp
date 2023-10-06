#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "lib.h"

// Тестим строки

class Strings :public ::testing::TestWithParam< std::pair<const char*, const char*> > {};

TEST_P(Strings, CompareStrings) {
    auto strings = GetParam();
    const char* str1 = strings.first;
    const char* str2 = strings.second;
    int num1 = std::stoi(str1),
    num2 = std::stoi(str2);

	// arrange
	Octal a(str1);
    Octal b(str2);

	// act
	bool less = (num1 < num2),
    greater = (num1 > num2),
    equals = (num1 == num2);

	// assert
	ASSERT_EQ((a < b), less);
	ASSERT_EQ((a > b), greater);
	ASSERT_EQ((a == b), equals);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	Strings,
	::testing::Values(
		std::pair<const char*, const char*>{"1332", "73220"},
        std::pair<const char*, const char*>{"2212", "111"},
        std::pair<const char*, const char*>{"362", "3021"},
        std::pair<const char*, const char*>{"11", "11"},
        std::pair<const char*, const char*>{"1000", "5321"}
));

// Тестим плохие литералы

class BadStrings :public ::testing::TestWithParam< const char* > {};

TEST_P(BadStrings, InitFromString) {
	// arrange
	const char* str = GetParam();

	// act
	// Ну мы просто знаем, что функция должна вернуть logic_error

	// assert
	ASSERT_THROW(Octal a(str), std::logic_error);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithIncorrect,
	BadStrings,
	::testing::Values(
        "902",
        "087",
        "9d7"
));

// Тетстим числа

class Numbers :public ::testing::TestWithParam< std::pair<int, int> > {};

TEST_P(Numbers, CompareNumbers) {
    auto numbers = GetParam();
    int num1 = numbers.first,
    num2 = numbers.second;

	// arrange
	Octal a(num1);
    Octal b(num2);

	// act
	bool less = (num1 < num2),
    greater = (num1 > num2),
    equals = (num1 == num2);

	// assert
	ASSERT_EQ((a < b), less);
	ASSERT_EQ((a > b), greater);
	ASSERT_EQ((a == b), equals);
}

TEST_P(Numbers, SumNumbers) {
    auto numbers = GetParam();
    int num1 = numbers.first,
    num2 = numbers.second;

	// arrange
	Octal a(num1);
    Octal b(num2);

	// act
	int sum = num1 + num2;

	// assert
	ASSERT_EQ((a + b).toInt(), sum);
}

INSTANTIATE_TEST_SUITE_P(
	Numbers_,
	Numbers,
	::testing::Values(
		std::pair<int, int>{1332, 73220},
        std::pair<int, int>{2212, 111},
        std::pair<int, int>{362, 3021},
        std::pair<int, int>{11, 11},
        std::pair<int, int>{1000, 532}
));

// Тестим разность

class NumbersForMinus :public ::testing::TestWithParam< std::pair<int, int> > {};

TEST_P(NumbersForMinus, MinusNumbers) {
    auto numbers = GetParam();
    int num1 = numbers.first,
    num2 = numbers.second;

	// arrange
	Octal a(num1);
    Octal b(num2);

	// act
	int sum = num1 - num2;

	// assert
	ASSERT_EQ((a - b).toInt(), sum);
}

INSTANTIATE_TEST_SUITE_P(
	NumbersForMinus_,
	NumbersForMinus,
	::testing::Values(
		std::pair<int, int>{73220, 1332},
        std::pair<int, int>{2212, 111},
        std::pair<int, int>{3021, 362},
        std::pair<int, int>{11, 11},
        std::pair<int, int>{1000, 532}
));

// Тестим плохую разность

class BadNumbersForMinus :public ::testing::TestWithParam< std::pair<int, int> > {};

TEST_P(BadNumbersForMinus, BadMinusNumbers) {
    auto numbers = GetParam();
    int num1 = numbers.first,
    num2 = numbers.second;

	// arrange
	Octal a(num1);
    Octal b(num2);

	// act
	// Ну мы просто знаем, что функция должна вернуть logic_error

	// assert
	ASSERT_THROW((a - b), std::logic_error);
}

INSTANTIATE_TEST_SUITE_P(
	BadNumbersForMinus_,
	BadNumbersForMinus,
	::testing::Values(
		std::pair<int, int>{1332, 73220},
        std::pair<int, int>{111, 2212},
        std::pair<int, int>{362, 3021},
        std::pair<int, int>{532, 1000}
));