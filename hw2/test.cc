#include "gtest/gtest.h"
#include "util.h"

class UtilTest : public ::testing::Test {
 protected :
  void SetUp() override { }
  void TearDown() override { }
  Util u;
};

TEST_F(UtilTest, UtilAddTest1) {
EXPECT_EQ(u.Add(1, 3) , 4);
}

TEST_F(UtilTest, UtilAddTest2) {
EXPECT_EQ(u.Add(4, 2) , 6);
}

TEST_F(UtilTest, UtilAddTest3) {
EXPECT_EQ(u.Add(1, 6) , 7);
}

TEST_F(UtilTest, UtilDivTest1) {
ASSERT_DEATH(u.Div(1, 0), "Divide-by-Zero");
}

TEST_F(UtilTest, UtilDivTest2) {
ASSERT_DEATH(u.Div(3, 0), "Divide-by-Zero");
}

TEST_F(UtilTest, UtilDivTest3) {
ASSERT_DEATH(u.Div(12, 0), "Divide-by-Zero");
}

TEST_F(UtilTest, UtilSubTest1) {
EXPECT_EQ(u.Sub(3, 2) , 1);
}

TEST_F(UtilTest, UtilSubTest2) {
EXPECT_EQ(u.Sub(5, 2) , 3);
}

TEST_F(UtilTest, UtilSubTest3) {
EXPECT_EQ(u.Sub(8, 1) , 7);
}

TEST_F(UtilTest, UtilMulTest1) {
EXPECT_EQ(u.Mul(3, 2) , 6);
}

TEST_F(UtilTest, UtilMulTest2) {
EXPECT_EQ(u.Mul(6, 2) , 12);
}

TEST_F(UtilTest, UtilMulTest3) {
EXPECT_EQ(u.Mul(4, 5) , 20);
}
