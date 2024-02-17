// https://leetcode.cn/problems/binary-tree-level-order-traversal-ii
#include "Common.h"

#include <iostream>

namespace BinaryTreeLevelOrderTraversalII {
    using std::vector;

    class Solution {
    public:
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            if (!root) return {};
            vector<vector<int>> res;
            vector<TreeNode*> row = {root};
            while (!row.empty()) {
                vector<int> row_val;
                vector<TreeNode*> next_row;
                for (auto node: row) {
                    row_val.push_back(node->val);
                    if (node->left) next_row.push_back(node->left);
                    if (node->right) next_row.push_back(node->right);
                }
                res.emplace_back(std::move(row_val));
                row = std::move(next_row);
            }
            std::reverse(res.begin(), res.end());
            return res;
        }
    };

    void runTest() {
        Solution solution;
        vector<std::string> testCases = {
                "[3,9,20,null,null,15,7]",
                "[1]",
                "[]"
        };
        for (const auto& test: testCases) {
            auto tree = buildBinaryTree(deserializeVector1d(test));
            auto&& res = solution.levelOrderBottom(tree);
            std::cout << serialize(res) << std::endl;
            destructTree(tree);
        }
    }
}
