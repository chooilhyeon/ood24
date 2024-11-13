#include "string_node.cc"

StringNode::StringNode(std::string value, const Node* left, const Node* right) {
value_ = value;
Node n = Node(left, right);
}

string StringNode::value() const {
return value_;
}

