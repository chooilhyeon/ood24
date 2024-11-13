#include "int_node.h"

IntNode::IntNode(int value, const Node* left, const Node* right) {
value_ = value;
Node n = Node(left, right);
}

int IntNode::value() const {
return value_;
}


