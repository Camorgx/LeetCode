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
extern TreeNode* build_tree(const std::vector<int>& data);

// Display a binary tree according to LeetCode's conventions
extern void display_tree(TreeNode* root);

extern void front_display_tree(TreeNode* root);

extern void destruct_tree(TreeNode* root);
