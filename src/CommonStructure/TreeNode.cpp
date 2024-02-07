#include "CommonStructure/TreeNode.h"

#include <queue>
#include <iostream>

using std::vector;
using std::queue;
using std::cout, std::endl;

TreeNode* build_tree(const vector<int>& data) {
	queue<TreeNode*> que;
	auto* root = new TreeNode(data[0]);
	que.push(root);
	int cnt = 1;
	while (!que.empty() && cnt < data.size()) {
		TreeNode* node = que.front();
		que.pop();
		if (data[cnt] != -1) {
			node->left = new TreeNode(data[cnt]);
			que.push(node->left);
		}
		++cnt;
		if (data[cnt] != -1) {
			node->right = new TreeNode(data[cnt]);
			que.push(node->right);
		}
		++cnt;
	}
	return root;
}

void front_display_tree(TreeNode* root) {
	if (!root) return;
	cout << root->val << ' ';
	front_display_tree(root->left);
	front_display_tree(root->right);
}

void destruct_tree(TreeNode* root) {
	if (!root) return;
	destruct_tree(root->left);
	destruct_tree(root->right);
	delete root;
}