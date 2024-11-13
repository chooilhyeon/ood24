#include "gtest/gtest.h"
#include "int_accumulator.h"
#include "float_accumulator.h"

class IntAccTest : public ::testing::Test {
 public:
IntAccTest() : accumulator_(3) {}

 protected:
void SetUp() override {}
void TearDown() override {}
int_accumulator::Accumulator accumulator_;
};

class FloatAccTest : public ::testing::Test {
 public:
FloatAccTest() : accumulator_(3) {}

 protected:
void SetUp() override {}
void TearDown() override {}
float_accumulator::Accumulator accumulator_;
};

TEST_F(IntAccTest, UtilAddTest1) {
accumulator_.Add(1);
EXPECT_EQ(accumulator_.acc() , 4);
}

TEST_F(IntAccTest, UtilAddTest2) {
accumulator_.Add(4);
EXPECT_EQ(accumulator_.acc() , 7);
}

TEST_F(IntAccTest, UtilAddTest3) {
accumulator_.Add(6);
EXPECT_EQ(accumulator_.acc() , 9);
}

TEST_F(IntAccTest, UtilDivTest1) {
ASSERT_DEATH(accumulator_.Div(0), "Divide-by-Zero");
}

TEST_F(IntAccTest, UtilDivTest2) {
ASSERT_DEATH(accumulator_.Div(0) , "Divide-by-Zero");
}

TEST_F(IntAccTest, UtilDivTest3) {
ASSERT_DEATH(accumulator_.Div(0) , "Divide-by-Zero");
}

TEST_F(IntAccTest, UtilSubTest1) {
accumulator_.Sub(2);
EXPECT_EQ(accumulator_.acc() , 1);
}

TEST_F(IntAccTest, UtilSubTest2) {
accumulator_.Sub(1);
EXPECT_EQ(accumulator_.acc() , 2);
}

TEST_F(IntAccTest, UtilSubTest3) {
accumulator_.Sub(3);
EXPECT_EQ(accumulator_.acc() , 0);
}

TEST_F(IntAccTest, UtilMulTest1) {
accumulator_.Mul(2);
EXPECT_EQ(accumulator_.acc() , 6);
}

TEST_F(IntAccTest, UtilMulTest2) {
accumulator_.Mul(4);
EXPECT_EQ(accumulator_.acc() , 12);
}

TEST_F(IntAccTest, UtilMulTest3) {
accumulator_.Mul(5);
EXPECT_EQ(accumulator_.acc() , 15);
}

TEST_F(FloatAccTest, UtilAddTest1) {
accumulator_.Add(1);
EXPECT_EQ(accumulator_.acc() , 4);
}

TEST_F(FloatAccTest, UtilAddTest2) {
accumulator_.Add(4);
EXPECT_EQ(accumulator_.acc() , 7);
}

TEST_F(FloatAccTest, UtilAddTest3) {
accumulator_.Add(6);
EXPECT_EQ(accumulator_.acc() , 9);
}

TEST_F(FloatAccTest, UtilDivTest1) {
ASSERT_DEATH(accumulator_.Div(0), "Divide-by-Zero");
}

TEST_F(FloatAccTest, UtilDivTest2) {
ASSERT_DEATH(accumulator_.Div(0) , "Divide-by-Zero");
}

TEST_F(FloatAccTest, UtilDivTest3) {
ASSERT_DEATH(accumulator_.Div(0) , "Divide-by-Zero");
}

TEST_F(FloatAccTest, UtilSubTest1) {
accumulator_.Sub(2);
EXPECT_EQ(accumulator_.acc() , 1);
}

TEST_F(FloatAccTest, UtilSubTest2) {
accumulator_.Sub(1);
EXPECT_EQ(accumulator_.acc() , 2);
}

TEST_F(FloatAccTest, UtilSubTest3) {
accumulator_.Sub(3);
EXPECT_EQ(accumulator_.acc() , 0);
}

TEST_F(FloatAccTest, UtilMulTest1) {
accumulator_.Mul(2);
EXPECT_EQ(accumulator_.acc() , 6);
}

TEST_F(FloatAccTest, UtilMulTest2) {
accumulator_.Mul(4);
EXPECT_EQ(accumulator_.acc() , 12);
}

TEST_F(FloatAccTest, UtilMulTest3) {
accumulator_.Mul(5);
EXPECT_EQ(accumulator_.acc() , 15);
}

