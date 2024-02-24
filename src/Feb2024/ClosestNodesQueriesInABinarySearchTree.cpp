// https://leetcode.cn/problems/closest-nodes-queries-in-a-binary-search-tree/
#include "Common.h"

#include <algorithm>
#include <iostream>

namespace ClosestNodesQueriesInABinarySearchTree {
    using std::vector;

    class Solution {
        std::vector<int> values;

        void getValues(TreeNode* root) {
            if (!root) return;
            getValues(root->left);
            values.push_back(root->val);
            getValues(root->right);
        }

    public:
        vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
            values.clear();
            getValues(root);
            vector<vector<int>> res;
            for (int q: queries) {
                auto pos = std::lower_bound(values.begin(), values.end(), q);
                if (pos == values.end()) res.emplace_back(vector<int> {*(pos - 1), -1});
                else if (*pos == q) res.emplace_back(vector<int> {q, q});
                else if (pos == values.begin()) res.emplace_back(vector<int> {-1, *pos});
                else res.emplace_back(vector<int> {*(pos - 1), *pos});
            }
            return res;
        }
    };

    void runTest() {
        Solution solution;
        vector<std::tuple<std::string, std::string>> testCases = {
            {
                "[6,2,13,1,4,9,15,null,null,null,null,null,null,14]",
                              "[2,5,16]"
            },
            {   "[4,null,9]", "[3]"}
        };
        for (auto&& [tree, queries]: testCases) {
            auto root = deserializeTreeNode(tree);
            auto query = deserializeVector1d(queries);
            std::cout << serialize(solution.closestNodes(root, query)) << std::endl;
            destructTree(root);
        }
    }
}