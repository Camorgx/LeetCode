// https://leetcode.cn/problems/binary-tree-postorder-traversal/
#include "Common.h"

#include <iostream>

namespace BinaryTreePostorderTraversal {
    using std::vector;

    class Solution {
        void dfs(vector<int>& vec, TreeNode* node) {
            if (!node) return;
            dfs(vec, node->left);
            dfs(vec, node->right);
            vec.push_back(node->val);
        }

    public:
        vector<int> postorderTraversal(TreeNode* root) {
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
            auto&& res = solution.postorderTraversal(tree);
            for (int x: res) std::cout << x << ' ';
            std::cout << std::endl;
            destructTree(tree);
        }
    }
}// namespace BinaryTreePostorderTraversal
