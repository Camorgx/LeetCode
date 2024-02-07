#include "CommonStructure.h"

#include <iostream>

namespace CrawlerLogFolder {
    using std::cout, std::endl;
    using std::vector, std::string;

    class Solution {
    public:
        int minOperations(vector<string>& logs) {
            int ans = 0;
            for (const string& log: logs) {
                if (log == "./") continue;
                else if (log == "../")
                    ans = ans > 0 ? ans - 1 : 0;
                else
                    ++ans;
            }
            return ans;
        }
    };

    void run_test() {
        vector<vector<string>> tests = {
                {"d1/", "d2/", "../", "d21/", "./"},
                {"d1/", "d2/", "./", "d3/", "../", "d31/"},
                {"d1/", "../", "../", "../"},
                {"./", "../", "./"}};
        Solution solution;
        for (auto& test: tests)
            cout << solution.minOperations(test) << endl;
    }
}// namespace CrawlerLogFolder