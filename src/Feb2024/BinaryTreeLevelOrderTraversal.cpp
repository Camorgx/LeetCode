// https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
#include "Common.h"

#include <iostream>

namespace BinaryTreeLevelOrderTraversal {
    using std::vector;

    class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
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
            return res;
        }
    };

    void run_test() {
        Solution solution;
        vector<std::string> testCases = {
                "[3,9,20,null,null,15,7]",
                "[1]",
                "[]"
        };
        for (const auto& test: testCases) {
            auto tree = build_tree(vectorDeserializer1d(test));
            auto&& res = solution.levelOrder(tree);
            std::cout << serialize(res) << std::endl;
            destruct_tree(tree);
        }
    }
}// namespace BinaryTreeLevelOrderTraversal