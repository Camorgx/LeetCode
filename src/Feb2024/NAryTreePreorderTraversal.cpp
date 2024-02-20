// https://leetcode.cn/problems/n-ary-tree-preorder-traversal/
#include "Common.h"

#include <iostream>
#include <stack>

namespace NAryTreePreorderTraversal {
    using std::vector;

    class Solution {
    public:
        vector<int> preorder(Node* root) {
            if (!root) return {};
            std::stack<std::tuple<Node*, int>> s;
            vector<int> res;
            s.emplace(root, 0);
            while (!s.empty()) {
                auto [node, dir] = s.top();
                s.pop();
                if (dir == 0) {
                    res.push_back(node->val);
                    if (!node->children.empty())
                        s.emplace(node, 1);
                }
                else if (dir == node->children.size())
                    s.emplace(node->children.back(), 0);
                else {
                    s.emplace(node, dir + 1);
                    s.emplace(node->children[dir - 1], 0);
                }
            }
            return res;
        }
    };

    void runTest() {
        Solution solution;
        vector<std::string> testCases = {
            "[1,null,3,2,4,null,5,6]",
            "[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,"
            "12,null,13,null,null,14]"
        };
        for (const auto& test: testCases) {
            auto tree = deserializeNode(test);
            auto&& res = solution.preorder(tree);
            std::cout << serialize(res) << std::endl;
            destructTree(tree);
        }
    }
}