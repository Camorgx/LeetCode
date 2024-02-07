// https://leetcode.cn/problems/cousins-in-binary-tree-ii/
#include "CommonStructure.h"

#include <iostream>
#include <queue>

namespace CousinsInBinaryTreeII {

    class Solution {
        auto get_layer_sum(TreeNode* root) {
            std::vector<int> res(2);
            std::queue<std::pair<int, TreeNode*>> q;// depth, node
            q.emplace(0, root);
            while (!q.empty()) {
                auto [dep, node] = q.front();
                q.pop();
                if (dep + 1 >= res.size())
                    res.emplace_back(0);
                res[dep] += node->val;
                if (node->left) q.emplace(dep + 1, node->left);
                if (node->right) q.emplace(dep + 1, node->right);
            }
            return res;
        }

    public:
        TreeNode* replaceValueInTree(TreeNode* root) {
            auto&& layer_sum = get_layer_sum(root);
            std::queue<std::pair<int, TreeNode*>> q;// depth, node
            q.emplace(0, root);
            root->val = 0;
            while (!q.empty()) {
                auto [dep, node] = q.front();
                q.pop();
                auto value = layer_sum[dep + 1];
                if (node->left) value -= node->left->val;
                if (node->right) value -= node->right->val;
                if (node->left) {
                    node->left->val = value;
                    q.emplace(dep + 1, node->left);
                }
                if (node->right) {
                    node->right->val = value;
                    q.emplace(dep + 1, node->right);
                }
            }
            return root;
        }
    };

    class BetterSolution {
    public:
        TreeNode* replaceValueInTree(TreeNode* root) {
            root->val = 0;
            std::vector<TreeNode*> layer = {root};
            while (!layer.empty()) {
                int layer_sum = 0;
                std::vector<TreeNode*> next_layer;
                for (auto node: layer) {
                    if (node->left) {
                        layer_sum += node->left->val;
                        next_layer.emplace_back(node->left);
                    }
                    if (node->right) {
                        layer_sum += node->right->val;
                        next_layer.emplace_back(node->right);
                    }
                }
                for (auto node: layer) {
                    int value = layer_sum;
                    if (node->left) value -= node->left->val;
                    if (node->right) value -= node->right->val;
                    if (node->left) node->left->val = value;
                    if (node->right) node->right->val = value;
                }
                layer = std::move(next_layer);
            }
            return root;
        }
    };

    void run_test() {
        Solution solution;
        BetterSolution betterSolution;
        std::vector<std::vector<int>> test_cases = {
                {5, 4, 9, 1, 10, -1, 7},
                {3, 1, 2},
                {436, 623, 376, 117, 698, 467, 818, 52, 543, 880, 577, 700, 568, 361, -1, 616, -1, 232, 656,
                 565, 12, -1, 95, -1, -1, -1, 389, 830, -1, 276, -1, 715, -1, 144, -1, 317, -1, -1, 91, -1,
                 -1, -1, -1, -1, -1, 129, 362, 487, 272, 275, -1, -1, 908, 559, -1, -1, -1, -1, -1, 862, -1,
                 -1, -1, -1, 68, 63, -1, 467, -1, 274, -1, -1, -1, -1, -1, 920, -1, 300}};
        for (const auto& test: test_cases) {
            auto tree = build_tree(test);
            auto res = solution.replaceValueInTree(tree);
            display_tree(res);
            std::cout << std::endl;
            destruct_tree(res);
            tree = build_tree(test);
            res = betterSolution.replaceValueInTree(tree);
            display_tree(res);
            std::cout << std::endl;
            destruct_tree(res);
        }
    }
}// namespace CousinsInBinaryTreeII
