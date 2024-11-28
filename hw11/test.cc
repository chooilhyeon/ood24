#include <gtest/gtest.h>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "sort.h"

template <typename T>
class SortTest : public ::testing::Test {
 public:
 SortTest() {}

 protected:
	std::vector<T> vector;
	std::list<T> list;
	std::stack<T> stack;
	std::queue<T> queue;

	void SetUp() override {}
	void TearDown() override {}
};

typedef ::testing::Types<int, char, std::string> MyTypes;
TYPED_TEST_SUITE(SortTest, MyTypes);

TYPED_TEST(SortTest, vectorTest1) {
    std::vector<int> vector = {4, 3, 2, 1};
	EXPECT_EQ("4 3 2 1 -> 1 2 3 4", SortAndPrint(&vector, IncreasingOrder<int>()));
}
