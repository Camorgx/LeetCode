// https://leetcode.cn/problems/deepest-leaves-sum/
#include "Common.h"

#include <iostream>

namespace DeepestLeavesSum {
    using std::cout, std::endl;
    using std::vector;

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
            max_depth = 1;
            max_sum = 0;
            _deepest_sum(root, 1);
            return max_sum;
        }
    };

    void runTest() {
        Solution solution;

        vector<int> set1 = {1, 2, 3, 4, 5, -1, 6, 7, -1, -1, -1, -1, 8};
        TreeNode* root1 = buildBinaryTree(set1);
        frontDisplayTree(root1);
        cout << endl;
        cout << solution.deepestLeavesSum(root1) << endl;
        destructTree(root1);

        vector<int> set2 = {6, 7, 8, 2, 7, 1, 3, 9, -1, 1, 4, -1, -1, -1, 5};
        TreeNode* root2 = buildBinaryTree(set2);
        frontDisplayTree(root2);
        cout << endl;
        cout << solution.deepestLeavesSum(root2) << endl;
        destructTree(root2);
    }
}// namespace DeepestLeavesSum