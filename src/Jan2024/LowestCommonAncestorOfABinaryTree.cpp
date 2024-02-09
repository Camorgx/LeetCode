// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
#include "CommonStructure.h"

#include <iostream>

namespace LowestCommonAncestorOfABinaryTree {
    class Solution {
        TreeNode* ans = nullptr;
        bool existInSubTree(TreeNode* root, TreeNode* p, TreeNode* q) {
            if (!root) return false;
            bool left = existInSubTree(root->left, p, q);
            bool right = existInSubTree(root->right, p, q);
            if ((left && right) || ((left || right) && (root == p || root == q)))
                ans = root;
            return left || right || root == p || root == q;
        }

    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            ans = root;
            existInSubTree(root, p, q);
            return ans;
        }
    };

    void run_test() {
        Solution solution;
        std::vector<std::tuple<std::vector<int>, int, int>> test_cases = {
                {{3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4}, 5, 1},
                {{3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4}, 5, 4},
                {{1, 2}, 1, 2},
        };
        for (auto&& [data, p_val, q_val]: test_cases) {
            auto tree = build_tree(data);
            auto p = find(tree, p_val);
            auto q = find(tree, q_val);
            std::cout << solution.lowestCommonAncestor(tree, p, q)->val << std::endl;
            destruct_tree(tree);
        }
    }
}// namespace LowestCommonAncestorOfABinaryTree
