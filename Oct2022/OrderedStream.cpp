// https://leetcode.cn/problems/design-an-ordered-stream/
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

namespace OrderedStream {
    using std::pair, std::make_pair;
    using std::vector;
    using std::string;
    using std::cout, std::endl;

    class OrderedStream {
        vector<string>* data;
        int ptr, max_size;
    public:
        OrderedStream(int n) {
            data = new vector<string>(n + 1, "");
            data->push_back("Init");
            ptr = 1;
            max_size = n;
        }

        ~OrderedStream() { delete data; }

        vector<string> insert(int idKey, string value) {
            (*data)[idKey] = value;
            vector<string> ans;
            while (ptr <= max_size && (*data)[ptr] != "")
                ans.emplace_back((*data)[ptr++]);
            return ans;
        }
    };

    void run_test() {
        OrderedStream* order_stream = new OrderedStream(5);
        pair<int, string> test_pair[5] = {
            make_pair(3, "ccccc"), make_pair(1, "aaaaa"),
            make_pair(2, "bbbbb"), make_pair(5, "eeeee"),
            make_pair(4, "ddddd")
        };
        for (const auto& i : test_pair) {
            auto res = order_stream->insert(i.first, i.second);
            cout << '[';
            for (const auto& j : res) cout << '\"' << j << "\", ";
            cout << "]\n";
        }
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */