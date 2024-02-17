#pragma once

#include <string>
#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, const std::vector<Node*>& _children) {
        val = _val;
        children = _children;
    }
};

extern std::string serialize(Node* root);

extern Node* deserializeNode(const std::string& str);

extern void destructTree(Node* root);
