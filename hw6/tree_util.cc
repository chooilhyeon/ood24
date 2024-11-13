#include "tree_util.h"

TreeUtil* TreeUtil::GetInstance() {
return instance_;
}

string TreeUtil::PreOrderTraversal(const Node* node) const {
if (node->value_ == null) {return;}
std::cout << std::to_string(node->value_) << std::endl;
PreOrderTraversal(node->left_);
PreOrderTraversal(node->right_);
}

string TreeUtil::InOrderTraversal(const Node* node) const {
if (node->value_ == null) {return;}
InOrderTraversal(node->left_);
std::cout << std::to_string(node->value_) << std::endl;
InOrderTraversal(node->right_);
}

string TreeUtil::PostOrderTraversal(const Node* node) const {
if (node->value_ == null) {return;}
PostOrderTraversal(node->left_);
PostOrderTraversal(node->right_);
std::cout << std::to_string(node->value_) << std::endl;
}
