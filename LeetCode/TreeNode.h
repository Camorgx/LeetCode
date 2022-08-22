#pragma once

#include <vector>

// LeetCode ͨ�ö������ڵ�
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// ʹ�ò�α�������һ�ö�����
extern TreeNode* build_tree(const std::vector<int>& data);

// �ṩ��������ǰ�����
extern void front_display_tree(TreeNode* root);

extern void destruct_tree(TreeNode* root);
