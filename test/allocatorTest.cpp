#include <allocator.h>
#include <gtest/gtest.h>

TEST(TestAllocatorSuite, TestAllocator) {
	// arrange
    Allocator<int, 100> allocator;

	// act
	// Ну мы просто знаем, что функция должна вернуть bad_alloc

	// assert
	ASSERT_THROW(allocator.allocate(101), std::bad_alloc);
}