#include <iostream>
#include <vector>

namespace LexicograhicallySmallestStringAfterASwap {
    using std::string;

    class Solution {
    public:
        string getSmallestString(string s) {
            auto len = s.length();
            for (auto i = 0; i < len - 1; ++i) {
                char ch1 = s[i], ch2 = s[i + 1];
                if ((ch2 - ch1) % 2 == 0 && ch1 > ch2) {
                    std::swap(s[i], s[i + 1]);
                    break;
                }
            }
            return s;
        }
    };

    void runTest() {
        Solution solution;
        std::vector<string> testCases = {"45320", "001"};
        for (auto& test: testCases)
            std::cout << solution.getSmallestString(test) << std::endl;
    }
}
