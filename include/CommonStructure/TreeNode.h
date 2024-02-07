#pragma once

#include <vector>

// LeetCode 通用二叉树节点
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 使用层次遍历建立一棵二叉树
extern TreeNode* build_tree(const std::vector<int>& data);

// 提供二叉树的前序遍历
extern void front_display_tree(TreeNode* root);

extern void destruct_tree(TreeNode* root);
