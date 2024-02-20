// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include "Common.h"

#include <iostream>
#include <unordered_map>

namespace ConstructBinaryTreeFromPreorderAndInorderTraversal {
    using std::vector;

    class Solution {
        using iter = vector<int>::iterator;
        std::unordered_map<int, iter> nodeMap;

        TreeNode* build(iter preLeft, iter preRight, iter inLeft, iter inRight) {
            if (preLeft > preRight) return nullptr;
            auto root = new TreeNode(*preLeft);
            auto inRoot = nodeMap[*preLeft];
            int leftTreeNodeNum = inRoot - inLeft;
            root->left = build(
                    preLeft + 1, preLeft + leftTreeNodeNum,
                    inLeft, inRoot - 1
            );
            root->right = build(
                    preLeft + leftTreeNodeNum + 1, preRight,
                    inRoot + 1, inRight
            );
            return root;
        }

    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            nodeMap.clear();
            for (auto val = inorder.begin(); val != inorder.end(); ++val)
                nodeMap[*val] = val;
            return build(
                    preorder.begin(), preorder.end() - 1,
                    inorder.begin(), inorder.end() - 1
            );
        }
    };

    void runTest() {
        Solution solution;
        vector<std::tuple<std::string, std::string>> testCases = {
                {"[3,9,20,15,7]", "[9,3,15,20,7]"},
                {"[-1]",          "[-1]"}
        };
        for (auto&& [preorder, inorder]: testCases) {
            auto pre = deserializeVector1d(preorder);
            auto in = deserializeVector1d(inorder);
            auto tree = solution.buildTree(pre, in);
            std::cout << serialize(tree) << std::endl;
            destructTree(tree);
        }
    }
}