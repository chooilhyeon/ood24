#include <gtest/gtest.h>
#include "vector.h"
#include "list.h"
#include "stack.h"
#include "queue.h"

class STLTest : public ::testing::Test {
public:
STLTest() {}
protected:
static Vector* vec;
static List* list;
static Stack* stack;
static Queue* queue;
void SetUp() override {}
void TearDown() override {}
};

TEST_F(STLTest, VectorTest1) {
	Vector vec;
	EXPECT_EQ(vec.size(), 0);
	EXPECT_TRUE(vec.IsEmpty());
}

TEST_F(STLTest, VectorTest2) {
	Vector vec;
	vec.PushBack(1);
	vec.PushBack(2);
	Vector vec2 = vec; // Deep copy test
	vec2.PushBack(3);
	EXPECT_EQ(vec.size(), 2);
	EXPECT_EQ(vec2.size(), 3);
}

TEST_F(STLTest, VectorTest3) {
	Vector vec;
	ASSERT_DEATH(vec.PopBack(), "Out-of-bound"); // Assertion test
}

TEST_F(STLTest, VectorTest4) {
	Vector vec;
	for(int i = 0; i < 10; i++) {
		vec.PushBack(i);
	}
	Vector vec2(vec);
	vec.PopBack();
	EXPECT_EQ(vec2.size(), 10); // Deep copy shouldn't be affected
	EXPECT_EQ(vec.size(), 9);
}

TEST_F(STLTest, VectorTest5) {
	Vector vec;
	vec.PushBack(1);
	ASSERT_DEATH(vec[1], "Out-of-bound"); // Assertion test
}

TEST_F(STLTest, ListTest1) {
	List list;
	EXPECT_EQ(list.size(), 0);
	EXPECT_TRUE(list.IsEmpty());
}

TEST_F(STLTest, ListTest2) {
	List list;
	list.PushBack(1);
	list.PushBack(2);
	List list2 = list; // Deep copy test
	list2.PushBack(3);
	EXPECT_EQ(list.size(), 2);
	EXPECT_EQ(list2.size(), 3);
}

TEST_F(STLTest, ListTest3) {
	List list;
	ASSERT_DEATH(list.PopFront(), "Out-of-bound"); // Assertion test
}

TEST_F(STLTest, ListTest4) {
	List list;
	for(int i = 0; i < 5; i++) {
		list.PushBack(i);
	}
	List list2(list);
	list.PopFront();
	EXPECT_EQ(list2.size(), 5); // Deep copy shouldn't be affected
	EXPECT_EQ(list.size(), 4);
}

TEST_F(STLTest, ListTest5) {
	List list;
	ASSERT_DEATH(list.Front(), "Out-of-bound"); // Assertion test
}

TEST_F(STLTest, StackTest1) {
	Stack stack;
	EXPECT_EQ(stack.size(), 0);
	EXPECT_TRUE(stack.IsEmpty());
}

TEST_F(STLTest, StackTest2) {
	Stack stack;
	stack.Push(1);
	stack.Push(2);
	Stack stack2 = stack; // Deep copy test
	stack2.Push(3);
	EXPECT_EQ(stack.size(), 2);
	EXPECT_EQ(stack2.size(), 3);
}

TEST_F(STLTest, StackTest3) {
	Stack stack;
	ASSERT_DEATH(stack.Pop(), "Out-of-bound"); // Assertion test
}

TEST_F(STLTest, StackTest4) {
	Stack stack;
	for(int i = 0; i < 5; i++) {
		stack.Push(i);
	}
	Stack stack2(stack);
	stack.Pop();
	EXPECT_EQ(stack2.size(), 5); // Deep copy shouldn't be affected
	EXPECT_EQ(stack.size(), 4);
}

TEST_F(STLTest, StackTest5) {
	Stack stack;
	ASSERT_DEATH(stack.Top(), "Out-of-bound"); // Assertion test
}

TEST_F(STLTest, QueueTest1) {
	Queue queue;
	EXPECT_EQ(queue.size(), 0);
	EXPECT_TRUE(queue.IsEmpty());
}

TEST_F(STLTest, QueueTest2) {
	Queue queue;
	queue.Add(1);
	queue.Add(2);
	Queue queue2 = queue; // Deep copy test
	queue2.Add(3);
	EXPECT_EQ(queue.size(), 2);
	EXPECT_EQ(queue2.size(), 3);
}

TEST_F(STLTest, QueueTest3) {
	Queue queue;
	ASSERT_DEATH(queue.Poll(), "Out-of-bound"); // Assertion test
}

TEST_F(STLTest, QueueTest4) {
	Queue queue;
	for(int i = 0; i < 5; i++) {
		queue.Add(i);
	}
	Queue queue2(queue);
	queue.Poll();
	EXPECT_EQ(queue2.size(), 5); // Deep copy shouldn't be affected
	EXPECT_EQ(queue.size(), 4);
}

TEST_F(STLTest, QueueTest5) {
	Queue queue;
	queue.Add(1);
	Queue queue2(queue);
	queue2.Poll();
	EXPECT_EQ(queue.size(), 1); // Original shouldn't be affected by deep copy operations
	EXPECT_TRUE(queue2.IsEmpty());
}


