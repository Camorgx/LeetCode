// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
#include "Common.h"

#include <iostream>

namespace LowestCommonAncestorOfABinarySearchTree {
    class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            TreeNode* res = root;
            while (true) {
                if (res->val > p->val && res->val > q->val)
                    res = res->left;
                else if (res->val < p->val && res->val < q->val)
                    res = res->right;
                else break;
            }
            return res;
        }
    };

    void runTest() {
        Solution solution;
        std::vector<std::tuple<std::string, int, int>> testCases = {
            {"[6,2,8,0,4,7,9,null,null,3,5]", 2, 8},
            {"[6,2,8,0,4,7,9,null,null,3,5]", 2, 4}
        };
        for (auto&& [data, p, q]: testCases) {
            auto tree = deserializeTreeNode(data);
            auto pNode = find(tree, p);
            auto qNode = find(tree, q);
            auto res = solution.lowestCommonAncestor(tree, pNode, qNode);
            std::cout << res->val << std::endl;
            destructTree(tree);
        }
    }
}
