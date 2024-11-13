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

if (auto intNode = dynamic_cast<const IntNode*>(root)) {
result += std::to_string(intNode->value());
} else if (auto stringNode = dynamic_cast<const StringNode*>(root)) {
result += stringNode->value();
}

std::string left = PreOrderTraversal(root->left());
if(!left.empty()) {
result += ", " + left;
}

std::string right = PreOrderTraversal(root->right());
if(!right.empty()) {
result += ", " + right;
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
result += left + ", ";
}

if (auto intNode = dynamic_cast<const IntNode*>(root)) {
result += std::to_string(intNode->value());
} else if (auto stringNode = dynamic_cast<const StringNode*>(root)) {
result += stringNode->value();
}

std::string right = InOrderTraversal(root->right());
if(!right.empty()) {
result += ", " + right;
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
result += left + ", ";
}

std::string right = PostOrderTraversal(root->right());
if(!right.empty()) {
result += right + ", ";
}

if (auto intNode = dynamic_cast<const IntNode*>(root)) {
result += std::to_string(intNode->value());
} else if (auto stringNode = dynamic_cast<const StringNode*>(root)) {
result += stringNode->value();
}

return result;
}
