#include "Common/Node.h"
#include "Common/utils.h"

#include <queue>

std::string serialize(Node* root) {
    if (!root) return "[]";
    std::vector<Node*> row = {root};
    std::vector<Node*> next_row;
    std::vector<std::string> items = {std::to_string(root->val), "null"};
    while (!row.empty()) {
        for (auto node: row) {
            for (auto child: node->children) {
                items.emplace_back(std::to_string(child->val));
                next_row.push_back(child);
            }
            items.emplace_back("null");
        }
        row = std::move(next_row);
    }
    for (int i = static_cast<int>(items.size()) - 1; i >= 0 && items[i] == "null"; --i)
        items.pop_back();
    return join(items, ",");
}

Node* deserializeNode(const std::string& str) {
    if (str == "[]") return nullptr;
    auto s = str.substr(1, str.length() - 2);
    auto&& items = stringSplit(s, ",");
    Node* root = new Node(std::stoi(std::string(items[0])));
    int cnt = 2;
    std::queue<Node*> que;
    que.push(root);
    while (!que.empty() && cnt < items.size()) {
        auto node = que.front();
        que.pop();
        std::vector<Node*> children;
        while (cnt < items.size() && items[cnt] != "null") {
            children.push_back(new Node(std::stoi(std::string(items[cnt++]))));
            que.push(children.back());
        }
        if (cnt < items.size() && items[cnt] == "null") ++cnt;
        node->children = std::move(children);
    }
    return root;
}

void destructTree(Node* root) {
    if (!root) return;
    std::vector<Node*> nodes;
    std::queue<Node*> que;
    que.push(root);
    while (!que.empty()) {
        auto node = que.front();
        que.pop();
        nodes.push_back(node);
        for (auto child: node->children)
            que.push(child);
    }
    for (auto node: nodes)
        delete node;
}
