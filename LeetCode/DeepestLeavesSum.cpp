// https://leetcode.cn/problems/deepest-leaves-sum/

#include <queue>
#include <vector>
#include <iostream>

namespace DeepestLeavesSum {
	using std::queue;
	using std::vector;
	using std::cout, std::endl;

	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};

	TreeNode* build_tree(const vector<int>& data) {
		queue<TreeNode*> que;
		TreeNode* root = new TreeNode(data[0]);
		que.push(root);
		int cnt = 1;
		while (que.size() && cnt < data.size()) {
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

	void display_tree(TreeNode* root) {
		if (!root) return;
		cout << root->val << ' ';
		display_tree(root->left);
		display_tree(root->right);
	}

	void destruct_tree(TreeNode* root) {
		if (!root) return;
		destruct_tree(root->left);
		destruct_tree(root->right);
		delete root;
	}

	class Solution {
		int max_depth = 1, max_sum = 0;
		void _deepest_sum(TreeNode* node, int depth) {
			if (!node) return;
			if (depth > max_depth) {
				max_depth = depth;
				max_sum = node->val;
			}
			else if (depth == max_depth) 
				max_sum += node->val;
			_deepest_sum(node->left, depth + 1);
			_deepest_sum(node->right, depth + 1);
		}
	public:
		int deepestLeavesSum(TreeNode* root) {
			max_depth = 1; max_sum = 0;
			_deepest_sum(root, 1);
			return max_sum;
		}
	};

	void run_test() {
		Solution solution;

		vector<int> set1 = { 1, 2, 3, 4, 5, -1, 6, 7, -1, -1, -1, -1, 8 };
		TreeNode* root1 = build_tree(set1);
		display_tree(root1);
		cout << endl;
		cout << solution.deepestLeavesSum(root1) << endl;
		destruct_tree(root1);

		vector<int> set2 = { 6, 7, 8, 2, 7, 1, 3, 9, -1, 1, 4, -1, -1, -1, 5 };
		TreeNode* root2 = build_tree(set2);
		display_tree(root2);
		cout << endl;
		cout << solution.deepestLeavesSum(root2) << endl;
		destruct_tree(root2);
	}
}