#ifndef _INT_NODE_H_
#define _INT_NODE_H_
#include "node.h"
#include <string>

class IntNode : public Node {
 public:
explicit IntNode(int value, const Node* left, const Node* right);
const std::string value() const override;
 private:
const int value_;
};

#endif  // _INT_NODE_H_
