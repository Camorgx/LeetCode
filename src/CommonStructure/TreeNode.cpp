#include "CommonStructure/TreeNode.h"

#include <iostream>
#include <queue>

using std::cout, std::endl;
using std::queue;
using std::vector;

TreeNode* build_tree(const vector<int>& data) {
    if (data.empty()) return nullptr;
    queue<TreeNode*> que;
    auto* root = new TreeNode(data[0]);
    que.push(root);
    int cnt = 1;
    while (!que.empty() && cnt < data.size()) {
        TreeNode* node = que.front();
        que.pop();
        if (data[cnt] != -1) {
            node->left = new TreeNode(data[cnt]);
            que.push(node->left);
        }
        ++cnt;
        if (cnt == data.size()) break;
        if (data[cnt] != -1) {
            node->right = new TreeNode(data[cnt]);
            que.push(node->right);
        }
        ++cnt;
    }
    return root;
}

void display_tree(TreeNode* root) {
    queue<TreeNode*> que;
    que.push(root);
    vector<int> list;
    while (!que.empty()) {
        auto node = que.front();
        que.pop();
        list.push_back(node ? node->val : -1);
        if (node) {
            que.push(node->left);
            que.push(node->right);
        }
    }
    int cnt = 0;
    for (auto i = list.rbegin(); *i == -1 && i != list.rend(); ++i)
        ++cnt;
    cnt = static_cast<int>(list.size()) - cnt;
    for (int i = 0; i < cnt; ++i)
        cout << list[i] << ' ';
}

void front_display_tree(TreeNode* root) {
    if (!root) return;
    cout << root->val << ' ';
    front_display_tree(root->left);
    front_display_tree(root->right);
}

void destruct_tree(TreeNode* root) {
    if (!root) return;
    destruct_tree(root->left);
    destruct_tree(root->right);
    delete root;
}

TreeNode* find(TreeNode* root, int val) {
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
        auto node = que.front();
        que.pop();
        if (node->val == val) return node;
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
    }
    return nullptr;
}
