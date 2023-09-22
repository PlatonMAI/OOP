#include <gtest/gtest.h>

#include "lib.h"

TEST(HelloTest, BasicAssertions) {
	// Обрабатываем случаи отрицательности
	EXPECT_EQ(GCD(17, 51), 17);
	EXPECT_EQ(GCD(-17, 51), 17);
	EXPECT_EQ(GCD(17, -51), 17);
	EXPECT_EQ(GCD(-17, -51), 17);
	
	// Смотрим, нет ли разницы, в каком порядке записывать числа
	EXPECT_EQ(GCD(51, 17), 17);
	EXPECT_EQ(GCD(-51, 17), 17);
	EXPECT_EQ(GCD(51, -17), 17);
	EXPECT_EQ(GCD(-51, -17), 17);

	// Теперь для чисел, среди которых изначально нет НОК
	EXPECT_EQ(GCD(12, 18), 6);
	EXPECT_EQ(GCD(75, 10000), 25);

	// Ну и для нулевых попыток
	EXPECT_EQ(GCD(0, 18), 0);
	EXPECT_EQ(GCD(75, 0), 0);
}