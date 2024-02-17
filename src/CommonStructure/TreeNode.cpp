#include "Common/TreeNode.h"
#include "Common/utils.h"

#include <iostream>
#include <queue>

using std::cout, std::endl;
using std::queue;
using std::vector;

TreeNode* buildBinaryTree(const std::vector<int>& data) {
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

void displayTree(TreeNode* root) {
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

void frontDisplayTree(TreeNode* root) {
    if (!root) return;
    cout << root->val << ' ';
    frontDisplayTree(root->left);
    frontDisplayTree(root->right);
}

void destructTree(TreeNode* root) {
    if (!root) return;
    destructTree(root->left);
    destructTree(root->right);
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

TreeNode* deserializeTreeNode(const std::string& str) {
    if (str == "[]") return nullptr;
    auto s = str.substr(1, str.length() - 2);
    auto&& items = stringSplit(s, ",");
    queue<TreeNode*> que;
    auto* root = new TreeNode(std::stoi(std::string(items[0])));
    que.push(root);
    int cnt = 1;
    while (!que.empty() && cnt < items.size()) {
        TreeNode* node = que.front();
        que.pop();
        if (items[cnt] != "null") {
            node->left = new TreeNode(std::stoi(std::string(items[cnt])));
            que.push(node->left);
        }
        ++cnt;
        if (cnt == items.size()) break;
        if (items[cnt] != "null") {
            node->right = new TreeNode(std::stoi(std::string(items[cnt])));
            que.push(node->right);
        }
        ++cnt;
    }
    return root;
}

std::string serialize(TreeNode* root) {
    if (!root) return "[]";
    queue<TreeNode*> que;
    que.push(root);
    vector<std::string> items;
    while (!que.empty()) {
        auto node = que.front();
        que.pop();
        items.emplace_back(node ? std::to_string(node->val) : "null");
        if (node) {
            que.push(node->left);
            que.push(node->right);
        }
    }
    for (int i = static_cast<int>(items.size()) - 1; i >= 0 && items[i] == "null"; --i)
        items.pop_back();
    return '[' + join(items, ",") + ']';
}
