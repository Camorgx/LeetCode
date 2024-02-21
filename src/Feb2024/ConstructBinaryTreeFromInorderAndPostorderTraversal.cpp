// https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
#include "Common.h"

#include <iostream>
#include <unordered_map>

namespace ConstructBinaryTreeFromInorderAndPostorderTraversal {
    using std::vector;

    class Solution {
        using iter = vector<int>::iterator;
        std::unordered_map<int, iter> nodeMap;

        TreeNode* build(iter inLeft, iter inRight, iter postLeft, iter postRight) {
            if (postLeft > postRight) return nullptr;
            auto root = new TreeNode(*postRight);
            auto inRoot = nodeMap[*postRight];
            int leftTreeNodeNum = inRoot - inLeft;
            root->left = build(
                inLeft, inRoot - 1,
                postLeft, postLeft + leftTreeNodeNum - 1
            );
            root->right = build(
                inRoot + 1, inRight,
                postLeft + leftTreeNodeNum, postRight - 1
            );
            return root;
        }

    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            nodeMap.clear();
            for (auto val = inorder.begin(); val != inorder.end(); ++val)
                nodeMap[*val] = val;
            return build(
                inorder.begin(), inorder.end() - 1,
                postorder.begin(), postorder.end() - 1
            );
        }
    };

    void runTest() {
        Solution solution;
        vector<std::tuple<std::string, std::string>> testCases = {
            {"[9,3,15,20,7]", "[9,15,7,20,3]"},
            {"[-1]",          "[-1]"}
        };
        for (auto&& [inorder, postorder]: testCases) {
            auto in = deserializeVector1d(inorder);
            auto post = deserializeVector1d(postorder);
            auto tree = solution.buildTree(in, post);
            std::cout << serialize(tree) << std::endl;
            destructTree(tree);
        }
    }
}
