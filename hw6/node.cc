#include "node.h"

Node::Node(const Node* left, const Node* right) {
left_ = left;
right_ = right;
}

Node::left() const {
return left_;
}

Node::right() const {
return right_;
}

Node::~Node() {

}
