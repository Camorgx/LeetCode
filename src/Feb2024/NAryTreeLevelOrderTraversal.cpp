// https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
#include "Common.h"

#include <iostream>

namespace NAryTreeLevelOrderTraversal {
    using std::vector;

    class Solution {
    public:
        vector<vector<int>> levelOrder(Node* root) {
            if (!root) return {};
            vector<vector<int>> res = {{root->val}};
            vector<Node*> row = {root};
            while (!row.empty()) {
                vector<int> rowVal;
                vector<Node*> nextRow;
                for (auto node: row) {
                    for (auto child: node->children) {
                        rowVal.push_back(child->val);
                        nextRow.push_back(child);
                    }
                }
                if (!rowVal.empty())
                    res.emplace_back(std::move(rowVal));
                row = std::move(nextRow);
            }
            return res;
        }
    };

    void runTest() {
        Solution solution;
        vector<std::string> testCases = {
            "[1,null,3,2,4,null,5,6]",
            "[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,"
            "11,null,12,null,13,null,null,14]",
        };
        for (const auto& test: testCases) {
            auto tree = deserializeNode(test);
            std::cout << serialize(tree) << std::endl;
            auto&& res = solution.levelOrder(tree);
            std::cout << serialize(res) << std::endl;
            destructTree(tree);
        }
    }
}
