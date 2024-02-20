// https://leetcode.cn/problems/design-an-ordered-stream/
#include <iostream>
#include <utility>
#include <vector>

namespace OrderedStream {
    using std::cout, std::endl;
    using std::pair, std::make_pair;
    using std::string;
    using std::vector;

    class OrderedStream {
        vector<string>* data;
        int ptr, max_size;

    public:
        explicit OrderedStream(int n) {
            data = new vector<string>(n + 1, "");
            data->emplace_back("Init");
            ptr = 1;
            max_size = n;
        }

        ~OrderedStream() { delete data; }

        vector<string> insert(int idKey, string value) {
            (*data)[idKey] = std::move(value);
            vector<string> ans;
            while (ptr <= max_size && !(*data)[ptr].empty())
                ans.emplace_back((*data)[ptr++]);
            return ans;
        }
    };

    void runTest() {
        auto* order_stream = new OrderedStream(5);
        pair<int, string> test_pair[5] = {
            make_pair(3, "c"), make_pair(1, "a"),
            make_pair(2, "b"), make_pair(5, "e"),
            make_pair(4, "d")
        };
        for (const auto& i: test_pair) {
            auto res = order_stream->insert(i.first, i.second);
            cout << '[';
            for (const auto& j: res) cout << '\"' << j << "\", ";
            cout << "]\n";
        }
        delete order_stream;
    }
}// namespace OrderedStream

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */