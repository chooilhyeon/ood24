#include <gtest/gtest.h>
#include "vector.h"
#include "list.h"
#include "stack.h"
#include "queue.h"

class STLTest : public ::testing::Test {
 public:
STLTest() {}

 protected:
static Vector<int>* vector;

static List<int>* list;

static Stack<int>* stack;

static Queue<int>* queue;

void SetUp() override {}
void TearDown() override {}
};

TEST_F(STLTest, VectorTest1) {
Vector<int> vector(4);
EXPECT_EQ(vector.size(), 0);
EXPECT_TRUE(vector.IsEmpty());
}

TEST_F(STLTest, VectorTest2) {
Vector<int> vector(4);
vector.PushBack(1);
vector.PushBack(2);
Vector vector2 = vector;
vector2.PushBack(3);
EXPECT_EQ(vector.size(), 2);
EXPECT_EQ(vector2.size(), 3);
}

TEST_F(STLTest, VectorTest3) {
Vector<int> vector(4);
ASSERT_DEATH(vector.PopBack(), "Out-of-bound");
}

TEST_F(STLTest, VectorTest4) {
Vector<int> vector(12);
for(int i = 0; i < 10; i++) {
vector.PushBack(i);
}
Vector<int> vector2(vector);
vector.PopBack();
EXPECT_EQ(vector2.size(), 10);
EXPECT_EQ(vector.size(), 9);
}

TEST_F(STLTest, VectorTest5) {
Vector<int> vector(4);
vector.PushBack(1);
ASSERT_DEATH(vector[1], "Out-of-bound");
}

TEST_F(STLTest, ListTest1) {
List<int> list;
EXPECT_EQ(list.size(), 0);
EXPECT_TRUE(list.IsEmpty());
}

TEST_F(STLTest, ListTest2) {
List<int> list;
list.PushBack(1);
list.PushBack(2);
List<int> list2 = list;
list2.PushBack(3);
EXPECT_EQ(list.size(), 2);
EXPECT_EQ(list2.size(), 3);
}

TEST_F(STLTest, ListTest3) {
List<int> list;
ASSERT_DEATH(list.PopFront(), "Out-of-bound");
}

TEST_F(STLTest, ListTest4) {
List<int> list;
for(int i = 0; i < 5; i++) {
list.PushBack(i);
}
List<int> list2(list);
list.PopFront();
EXPECT_EQ(list2.size(), 5);
EXPECT_EQ(list.size(), 4);
}

TEST_F(STLTest, ListTest5) {
List<int> list;
ASSERT_DEATH(list.PopFront(), "Out-of-bound");
}

TEST_F(STLTest, StackTest1) {
Stack<int> stack(4);
EXPECT_EQ(stack.size(), 0);
EXPECT_TRUE(stack.IsEmpty());
}

TEST_F(STLTest, StackTest2) {
Stack<int> stack(4);
stack.Push(1);
stack.Push(2);
Stack<int> stack2 = stack;
stack2.Push(3);
EXPECT_EQ(stack.size(), 2);
EXPECT_EQ(stack2.size(), 3);
}

TEST_F(STLTest, StackTest3) {
Stack<int> stack(4);
ASSERT_DEATH(stack.Pop(), "Out-of-bound");
}

TEST_F(STLTest, StackTest4) {
Stack<int> stack(4);
for(int i = 0; i < 5; i++) {
stack.Push(i);
}
Stack<int> stack2(stack);
stack.Pop();
EXPECT_EQ(stack2.size(), 5);
EXPECT_EQ(stack.size(), 4);
}

TEST_F(STLTest, StackTest5) {
Stack<int> stack(4);
ASSERT_DEATH(stack.Pop(), "Out-of-bound");
}

TEST_F(STLTest, QueueTest1) {
Queue<int> queue;
EXPECT_EQ(queue.size(), 0);
EXPECT_TRUE(queue.IsEmpty());
}

TEST_F(STLTest, QueueTest2) {
Queue<int> queue;
queue.Add(1);
queue.Add(2);
Queue<int> queue2 = queue;
queue2.Add(3);
EXPECT_EQ(queue.size(), 2);
EXPECT_EQ(queue2.size(), 3);
}

TEST_F(STLTest, QueueTest3) {
Queue<int> queue;
ASSERT_DEATH(queue.Poll(), "Out-of-bound");
}

TEST_F(STLTest, QueueTest4) {
Queue<int> queue;
for(int i = 0; i < 5; i++) {
queue.Add(i);
}
Queue<int> queue2(queue);
queue.Poll();
EXPECT_EQ(queue2.size(), 5);
EXPECT_EQ(queue.size(), 4);
}

TEST_F(STLTest, QueueTest5) {
Queue<int> queue;
queue.Add(1);
Queue<int> queue2(queue);
queue2.Poll();
EXPECT_EQ(queue.size(), 1);
EXPECT_TRUE(queue2.IsEmpty());
}
