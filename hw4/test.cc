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
ASSERT_DEATH(intset_.Add(17), "Exceeded capacity");
}

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

TEST_F(IntSetTest, UtillSetTest5) {
intset_.Add(4);
intset_.Add(13);
intset_.Add(15);
istest_.Add(3);
istest_.Add(5);
istest_.Add(8);
intset_.Add(istest_);
ASSERT_DEATH(intset_.Add(17), "Exceeded capacity");
}

TEST_F(IntSetTest, UtillSetTest6) {
intset_.Add(4);
intset_.Add(13);
intset_.Add(23);
EXPECT_FALSE(intset_.ForAll(bo));
}

TEST_F(IntSetTest, UtillSetTest7) {
intset_.Add(4);
intset_.Add(8);
intset_.Add(15);
EXPECT_TRUE(intset_.ForAll(bo));
}

TEST_F(IntSetTest, UtillSetTest8) {
intset_.Add(4);
intset_.Add(13);
intset_.Add(15);
intset_.Map(du);
intset_.Add(4);
EXPECT_EQ(intset_.size(), 4);
}

TEST_F(IntSetTest, UtillSetTest9) {
intset_.Add(4);
intset_.Add(13);
intset_.Add(15);
intset_.Map(du);
intset_.Add(8);
EXPECT_EQ(intset_.size(), 3);
}

TEST_F(IntSetTest, UtillSetTest10) {
intset_.Add(4);
intset_.Add(13);
intset_.Add(15);
istest_.Add(3);
istest_.Add(5);
istest_.Add(8);
intset_.Add(istest_);
EXPECT_TRUE(intset_.ForAll(bo));
}

TEST_F(IntSetTest, UtillSetTest11) {
intset_.Add(4);
intset_.Add(9);
intset_.Add(15);
istest_.Add(3);
istest_.Add(5);
istest_.Add(8);
intset_.Add(istest_);
intset_.Map(du);
EXPECT_FALSE(intset_.ForAll(bo));
}

TEST_F(IntSetTest, UtillSetTest12) {
intset_.Add(4);
intset_.Add(15);
istest_.Add(3);
istest_.Add(5);
istest_.Add(8);
intset_.Add(istest_);
intset_.Map(du);
intset_.Add(30);
EXPECT_EQ(intset_.size(), 5);
}
