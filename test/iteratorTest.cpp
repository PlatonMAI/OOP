#include <iterator.h>
#include <vector>
#include <gtest/gtest.h>

TEST(TestIteratorSuite, TestIterator) {
	// arrange
    std::vector<int> a(10, 10);
    Iterator<int, std::vector<int>> it(&a, 2, 10);

	// act
	(*it) = 5;

	// assert
	ASSERT_EQ(*it, 5);
}