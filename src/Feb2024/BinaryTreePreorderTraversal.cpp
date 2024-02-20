// https://leetcode.cn/problems/binary-tree-preorder-traversal/
#include "Common.h"

#include <iostream>

namespace BinaryTreePreorderTraversal {
    using std::vector;

    class Solution {
        void dfs(vector<int>& ans, TreeNode* node) {
            if (!node) return;
            ans.push_back(node->val);
            dfs(ans, node->left);
            dfs(ans, node->right);
        }

    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> ans;
            dfs(ans, root);
            return ans;
        }
    };

    void runTest() {
        Solution solution;
        vector<vector<int>> test_cases = {
            {1, -1, 2, 3},
            {},
            {1}};
        for (auto&& test: test_cases) {
            auto tree = buildBinaryTree(test);
            auto&& res = solution.preorderTraversal(tree);
            for (int i: res)
                std::cout << i << ' ';
            std::cout << std::endl;
            destructTree(tree);
        }
    }
}// namespace BinaryTreePreorderTraversal