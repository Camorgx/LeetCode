// https://leetcode.cn/problems/vertical-order-traversal-of-a-binary-tree/

#include "Common.h"

#include <algorithm>
#include <iostream>
#include <tuple>

namespace VerticalOrderTraversalOfABinaryTree {
    using std::vector;

    class Solution {
        using tuple_vec = vector<std::tuple<int, int, int>>;

        void dfs(tuple_vec& vec, TreeNode* node, int col, int row) {
            if (!node) return;
            vec.emplace_back(col, row, node->val);
            dfs(vec, node->left, col - 1, row + 1);
            dfs(vec, node->right, col + 1, row + 1);
        }

    public:
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            tuple_vec vec;
            dfs(vec, root, 0, 0);
            std::sort(vec.begin(), vec.end());
            vector<vector<int>> res;
            int lastCol = -1000;
            for (auto [col, row, val]: vec) {
                if (col != lastCol) {
                    lastCol = col;
                    res.emplace_back();
                }
                res.back().push_back(val);
            }
            return res;
        }
    };

    void run_test() {
        Solution solution;
        vector<std::string> testCases = {
                "[3,9,20,null,null,15,7]",
                "[1,2,3,4,5,6,7]",
                "[1,2,3,4,6,5,7]"
        };
        for (const auto& test: testCases) {
            auto&& data = vectorDeserializer1d(test);
            auto tree = build_tree(data);
            auto&& res = solution.verticalTraversal(tree);
            std::cout << serialize(res) << std::endl;
            destruct_tree(tree);
        }
    }
}// namespace VerticalOrderTraversalOfABinaryTree