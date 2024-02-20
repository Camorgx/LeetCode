// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
#include "Common.h"

#include <iostream>

namespace BinaryTreeZigzagLevelOrderTraversal {
    using std::vector;

    class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            if (!root) return {};
            vector<vector<int>> res = {{root->val}};
            vector<TreeNode*> row = {root};
            for (bool rev = true; !row.empty(); rev = !rev) {
                vector<int> row_val;
                vector<TreeNode*> next_row;
                for (auto node: row) {
                    if (node->left) {
                        next_row.push_back(node->left);
                        row_val.push_back(node->left->val);
                    }
                    if (node->right) {
                        next_row.push_back(node->right);
                        row_val.push_back(node->right->val);
                    }
                }
                if (!row_val.empty()) {
                    if (rev) res.emplace_back(row_val.rbegin(), row_val.rend());
                    else res.emplace_back(std::move(row_val));
                }
                row = std::move(next_row);
            }
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
            auto tree = deserializeTreeNode(test);
            std::cout << serialize(tree) << std::endl;
            auto&& res = solution.zigzagLevelOrder(tree);
            std::cout << serialize(res) << std::endl;
            destructTree(tree);
        }
    }
}
