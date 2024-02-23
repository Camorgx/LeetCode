// https://leetcode.cn/problems/kth-largest-sum-in-a-binary-tree/
#include "Common.h"

#include <iostream>

namespace KthLargestSumInABinaryTree {
    class Solution {
    public:
        long long kthLargestLevelSum(TreeNode* root, int k) {
            std::vector<TreeNode*> row = {root};
            std::vector<long long> rowSum;
            while (!row.empty()) {
                std::vector<TreeNode*> nextRow;
                long long sum = 0;
                for (auto node: row) {
                    sum += node->val;
                    if (node->left) nextRow.push_back(node->left);
                    if (node->right) nextRow.push_back(node->right);
                }
                row = std::move(nextRow);
                rowSum.push_back(sum);
            }
            std::nth_element(rowSum.begin(), rowSum.begin() + k - 1,
                             rowSum.end(), std::greater<long long>());
            return (k > rowSum.size()) ? -1 : rowSum[k - 1];
        }
    };

    void runTest() {
        Solution solution;
        std::vector<std::tuple<std::string, int>> testCases = {
            {"[5,8,9,2,1,3,7,4,6]", 2},
            {"[1,2,null,3]", 1},
            {"[897935,796748,528909,null,null,null,905326,706311,null,null,282251,null,139169]",
             4},
        };
        for (auto&& [data, k]: testCases) {
            auto tree = deserializeTreeNode(data);
            auto res = solution.kthLargestLevelSum(tree, k);
            std::cout << res << std::endl;
            destructTree(tree);
        }
    }
}
