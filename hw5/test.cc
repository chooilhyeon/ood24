#include "gtest/gtest.h"
#include "int_set.h"

class IntSetTest : public ::testing::Test {
 public:
IntSetTest() : intset_(6), istest_(3) {}
std::function<bool(int)> bo = [](int i) {
if (i < 22) {
return true;
} else {
return false;
}
};
std::function<int(int)> du = [](int i) {
return i * 2;
};

 protected:
void SetUp() override {}
void TearDown() override {}
IntSet intset_;
IntSet istest_;
};

TEST_F(IntSetTest, UtillSetTest1) {
intset_.Add(4);
intset_.Add(11);
intset_.Add(4);
EXPECT_EQ(intset_.size(), 2);
}

TEST_F(IntSetTest, UtillSetTest2) {
intset_.Add(4);
intset_.Add(13);
intset_.Add(15);
EXPECT_EQ(intset_.size(), 3);
}

TEST_F(IntSetTest, UtillSetTest3) {
intset_.Add(4);
intset_.Add(13);
intset_.Add(15);
intset_.Add(3);
intset_.Add(11);
intset_.Add(12);
intset_.Add(17);
EXPECT_EQ(intset_.size(), 7);
}

// Add(const IntSet& int_set)
TEST_F(IntSetTest, UtillSetTest4) {
intset_.Add(4);
intset_.Add(13);
intset_.Add(15);
istest_.Add(3);
istest_.Add(5);
istest_.Add(8);
intset_.Add(istest_);
EXPECT_EQ(intset_.size(), 6);
}

// Add(const IntSet& int_set)
TEST_F(IntSetTest, UtillSetTest5) {
intset_.Add(4);
intset_.Add(13);
intset_.Add(15);
istest_.Add(3);
istest_.Add(5);
istest_.Add(8);
intset_.Add(istest_);
intset_.Add(17);
EXPECT_EQ(intset_.size(), 7);
}

// Add(const IntSet& int_set)
TEST_F(IntSetTest, UtillSetTest6) {
intset_.Add(4);
intset_.Add(13);
intset_.Add(15);
istest_.Add(3);
istest_.Add(5);
istest_.Add(8);
intset_.Add(istest_);
EXPECT_TRUE(intset_.ForAll(bo));
}

// operator[]
TEST_F(IntSetTest, UtillSetTest7) {
intset_.Add(4);
intset_.Add(9);
intset_.Add(15);
EXPECT_EQ(intset_.operator[](2), 15);
}

// operator[]
TEST_F(IntSetTest, UtillSetTest8) {
intset_.Add(4);
intset_.Add(15);
istest_.Add(3);
istest_.Add(5);
istest_.Add(8);
intset_.Add(istest_);
intset_.Add(30);
ASSERT_DEATH(intset_.operator[](13), "Out-of-bound");
}

// operator[]
TEST_F(IntSetTest, UtillSetTest9) {
intset_.Add(4);
intset_.Add(15);
istest_.Add(3);
istest_.Add(5);
istest_.Add(8);
intset_.Add(istest_);
intset_.Add(30);
EXPECT_EQ(intset_.operator[](3), 5);
}
