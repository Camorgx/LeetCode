// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
#include "Common.h"

#include <iostream>
#include <unordered_map>

namespace ConstructBinaryTreeFromPreorderAndPostorderTraversal {
    using std::vector;

    class Solution {
        using iter = vector<int>::iterator;
        std::unordered_map<int, iter> nodeMap;

        TreeNode* build(iter preLeft, iter preRight, iter postLeft, iter postRight) {
            if (preLeft > preRight) return nullptr;
            if (preLeft == preRight) return new TreeNode(*preLeft);
            auto root = new TreeNode(*preLeft);
            auto leftRoot = nodeMap[*(preLeft + 1)];
            int leftTreeNodeNum = leftRoot - postLeft + 1;
            root->left = build(
                preLeft + 1, preLeft + leftTreeNodeNum,
                postLeft, leftRoot
            );
            root->right = build(
                preLeft + leftTreeNodeNum + 1, preRight,
                leftRoot + 1, postRight - 1
            );
            return root;
        }

    public:
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            nodeMap.clear();
            for (auto val = postorder.begin(); val != postorder.end(); ++val)
                nodeMap[*val] = val;
            return build(
                preorder.begin(), preorder.end() - 1,
                postorder.begin(), postorder.end() - 1
            );
        }
    };

    void runTest() {
        Solution solution;
        vector<std::tuple<std::string, std::string>> testCases = {
            {"[1,2,4,5,3,6,7]", "[4,5,2,6,7,3,1]"},
            {"[-1]",            "[-1]"}
        };
        for (auto&& [preorder, inorder]: testCases) {
            auto pre = deserializeVector1d(preorder);
            auto in = deserializeVector1d(inorder);
            auto tree = solution.constructFromPrePost(pre, in);
            std::cout << serialize(tree) << std::endl;
            destructTree(tree);
        }
    }
}
