#include "tree_util.h"
#include "int_node.h"
#include "string_node.h"
#include <sstream>
#include <string>

TreeUtil::TreeUtil() {}

TreeUtil* TreeUtil::GetInstance() {
static TreeUtil instance;
return &instance;
}

const std::string TreeUtil::PreOrderTraversal(const Node* root) const {
if (!root) {
return "";
}
std::string result;

result += root->value();

std::string left = PreOrderTraversal(root->left());
if(!left.empty()) {
result += "," + left;
}

std::string right = PreOrderTraversal(root->right());
if(!right.empty()) {
result += "," + right;
}

return result;
}

const std::string TreeUtil::InOrderTraversal(const Node* root) const {
if (!root) {
return "";
}
std::string result;

std::string left = InOrderTraversal(root->left());
if(!left.empty()) {
result += left + ",";
}

result += root->value();

std::string right = InOrderTraversal(root->right());
if(!right.empty()) {
result += "," + right;
}

return result;
}

const std::string TreeUtil::PostOrderTraversal(const Node* root) const {
if (!root) {
return "";
}
std::string result;

std::string left = PostOrderTraversal(root->left());
if(!left.empty()) {
result += left + ",";
}

std::string right = PostOrderTraversal(root->right());
if(!right.empty()) {
result += right + ",";
}

result += root->value();

return result;
}
