#pragma once

#include <vector>

// LeetCode Common Binary Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Build a binary tree according to LeetCode's conventions
extern TreeNode* buildBinaryTree(const std::vector<int>& data);

// Display a binary tree according to LeetCode's conventions
extern void displayTree(TreeNode* root);

extern void frontDisplayTree(TreeNode* root);

extern void destructTree(TreeNode* root);

extern TreeNode* find(TreeNode* root, int val);

extern TreeNode* deserializeTreeNode(const std::string& str);

extern std::string serialize(TreeNode* root);
