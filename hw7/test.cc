#include <gtest/gtest.h>
#include "int_node.h"
#include "tree_util.h"
#include "string_node.h"
#include <string>

class TreeUtilTest : public ::testing::Test{
 public:
TreeUtilTest() {}
 protected:
static TreeUtil* tree;
void SetUp() override {}
void TearDown() override {}
};

TEST(TreeUtilTest, PreOrderTraversal_Int) {
IntNode* left = new IntNode(2, nullptr, nullptr);
IntNode* right = new IntNode(3, nullptr, nullptr);
IntNode* root = new IntNode(1, left, right);

std::string result = TreeUtil::GetInstance()->PreOrderTraversal(root);
EXPECT_EQ(result, "1,2,3");
}

TEST(TreeUtilTest, PreOrderTraversal_String) {
StringNode* left = new StringNode("a", nullptr, nullptr);
StringNode* right = new StringNode("b", nullptr, nullptr);
StringNode* root = new StringNode("c", left, right);

std::string result = TreeUtil::GetInstance()->PreOrderTraversal(root);
EXPECT_EQ(result, "c,a,b");
}

TEST(TreeUtilTest, PreOrderTraversal) {
IntNode* Node_2 = new IntNode(2, nullptr, nullptr);
IntNode* Node_3  = new IntNode(3, nullptr, nullptr);
StringNode* left = new StringNode("a", Node_2, nullptr);
StringNode* right = new StringNode("b", Node_3, nullptr);
StringNode* root = new StringNode("c", left, right);

std::string result = TreeUtil::GetInstance()->PreOrderTraversal(root);
EXPECT_EQ(result, "c,a,2,b,3");
}

TEST(TreeUtilTest, InOrderTraversal_Int) {
IntNode* left = new IntNode(2, nullptr, nullptr);
IntNode* right = new IntNode(3, nullptr, nullptr);
IntNode* root = new IntNode(1, left, right);

std::string result = TreeUtil::GetInstance()->InOrderTraversal(root);
EXPECT_EQ(result, "2,1,3");
}

TEST(TreeUtilTest, InOrderTraversal_String) {
StringNode* left = new StringNode("a", nullptr, nullptr);
StringNode* right = new StringNode("b", nullptr, nullptr);
StringNode* root = new StringNode("c", left, right);

std::string result = TreeUtil::GetInstance()->InOrderTraversal(root);
EXPECT_EQ(result, "a,c,b");
}

TEST(TreeUtilTest, InOrderTraversal) {
IntNode* Node_2 = new IntNode(2, nullptr, nullptr);
IntNode* Node_3  = new IntNode(3, nullptr, nullptr);
StringNode* left = new StringNode("a", Node_2, nullptr);
StringNode* right = new StringNode("b", Node_3, nullptr);
StringNode* root = new StringNode("c", left, right);

std::string result = TreeUtil::GetInstance()->InOrderTraversal(root);
EXPECT_EQ(result, "2,a,c,3,b");
}

TEST(TreeUtilTest, PostOrderTraversal_Int) {
IntNode* left = new IntNode(2, nullptr, nullptr);
IntNode* right = new IntNode(3, nullptr, nullptr);
IntNode* root = new IntNode(1, left, right);

std::string result = TreeUtil::GetInstance()->PostOrderTraversal(root);
EXPECT_EQ(result, "2,3,1");
}

TEST(TreeUtilTest, PostOrderTraversal_String) {
StringNode* left = new StringNode("a", nullptr, nullptr);
StringNode* right = new StringNode("b", nullptr, nullptr);
StringNode* root = new StringNode("c", left, right);

std::string result = TreeUtil::GetInstance()->PostOrderTraversal(root);
EXPECT_EQ(result, "a,b,c");
}

TEST(TreeUtilTest, PostOrderTraversal) {
IntNode* Node_2 = new IntNode(2, nullptr, nullptr);
IntNode* Node_3  = new IntNode(3, nullptr, nullptr);
StringNode* left = new StringNode("a", Node_2, nullptr);
StringNode* right = new StringNode("b", Node_3, nullptr);
StringNode* root = new StringNode("c", left, right);

std::string result = TreeUtil::GetInstance()->PostOrderTraversal(root);
EXPECT_EQ(result, "2,a,3,b,c");
}

