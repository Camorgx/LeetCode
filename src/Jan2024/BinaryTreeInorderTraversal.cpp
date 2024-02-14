// https://leetcode.cn/problems/binary-tree-inorder-traversal/
#include "Common.h"

#include <iostream>

namespace BinaryTreeInorderTraversal {
    using std::vector;

    class Solution {
        void dfs(vector<int>& ans, TreeNode* node) {
            if (!node) return;
            dfs(ans, node->left);
            ans.push_back(node->val);
            dfs(ans, node->right);
        }

    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            dfs(res, root);
            return res;
        }
    };

    void run_test() {
        Solution solution;
        vector<vector<int>> test_cases = {
                {1, -1, 2, 3},
                {},
                {1},
        };
        for (auto&& data: test_cases) {
            auto tree = build_tree(data);
            auto&& res = solution.inorderTraversal(tree);
            for (int x: res) std::cout << x << ' ';
            std::cout << std::endl;
            destruct_tree(tree);
        }
    }
}// namespace BinaryTreeInorderTraversal
