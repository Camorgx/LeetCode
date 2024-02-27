// https://leetcode.cn/problems/range-sum-of-bst/
#include "Common.h"

#include <iostream>
#include <queue>

namespace RangeSumOfBst {
    class Solution {
    public:
        int rangeSumBST(TreeNode* root, int low, int high) {
            int sum = 0;
            std::queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                auto node = q.front();
                q.pop();
                if (node == nullptr) continue;
                if (node->val > high) q.push(node->left);
                else if (node->val < low) q.push(node->right);
                else {
                    sum += node->val;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            return sum;
        }
    };

    void runTest() {
        Solution solution;
        std::vector<std::tuple<std::string, int, int>> testCases = {
            {"[10,5,15,3,7,null,18]",        7, 15},
            {"[10,5,15,3,7,13,18,1,null,6]", 6, 10},
        };
        for (auto&& [data, low, high]: testCases) {
            auto tree = deserializeTreeNode(data);
            std::cout << solution.rangeSumBST(tree, low, high) << std::endl;
            destructTree(tree);
        }
    }
}
