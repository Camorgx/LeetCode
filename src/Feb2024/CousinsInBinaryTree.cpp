// https://leetcode.cn/problems/cousins-in-binary-tree/
#include "Common.h"

#include <iostream>
#include <queue>

namespace CousinsInBinaryTree {
    class Solution {
    public:
        bool isCousins(TreeNode* root, int x, int y) {
            TreeNode* parent_x = nullptr, * parent_y = nullptr;
            int dep_x = 0, dep_y = 0;
            std::queue<std::tuple<int, TreeNode*>> que;
            que.emplace(0, root);
            while (!que.empty() && (!parent_x || !parent_y)) {
                auto [dep, node] = que.front();
                que.pop();
                if (node->left) {
                    que.emplace(dep + 1, node->left);
                    if (node->left->val == x) {
                        parent_x = node;
                        dep_x = dep + 1;
                    }
                    if (node->left->val == y) {
                        parent_y = node;
                        dep_y = dep + 1;
                    }
                }
                if (node->right) {
                    que.emplace(dep + 1, node->right);
                    if (node->right->val == x) {
                        parent_x = node;
                        dep_x = dep + 1;
                    }
                    if (node->right->val == y) {
                        parent_y = node;
                        dep_y = dep + 1;
                    }
                }
            }
            return dep_x == dep_y && parent_x != parent_y;
        }
    };

    void runTest() {
        Solution solution;
        std::vector<std::tuple<std::vector<int>, int, int>> test_cases = {
            {{1, 2, 3, 4},            4, 3},
            {{1, 2, 3, -1, 4, -1, 5}, 5, 4},
            {{1, 2, 3, -1, 4},        2, 3}};
        for (auto&& [data, x, y]: test_cases) {
            auto tree = buildBinaryTree(data);
            std::cout << solution.isCousins(tree, x, y) << std::endl;
            destructTree(tree);
        }
    }
}// namespace CousinsInBinaryTree
