// https://leetcode.cn/problems/maximum-equal-frequency/

#include <vector>
#include <iostream>
#include <unordered_map>

namespace MaxEqualFreq {
    using std::vector;
    using std::unordered_map;
    using std::cout, std::endl;

    class Solution {
    public:
        int maxEqualFreq(vector<int>& nums) {
            // count[i] = j 表示数 i 出现了 j 次
            // freq[i] = j 表示出现次数为 i 的数共有 j 个
            unordered_map<int, int> count, freq;
            int max_count = 0, ans = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (count[nums[i]]) --freq[count[nums[i]]];
                max_count = std::max(max_count, ++count[nums[i]]);
                ++freq[count[nums[i]]];
                // 三种情况
                // 1. 最大出现次数是 1.
                // 2. 所有数的出现次数均为 max_count - 1, 只有一个是 max_count.
                // 3. 某一个数的出现次数是 1, 其余是 max_count.
                if (max_count == 1 ||
                    (freq[max_count] == 1 && (max_count - 1) * freq[max_count - 1] + max_count == i + 1) ||
                    (freq[1] == 1 && freq[max_count] * max_count + 1 == i + 1))
                    ans = std::max(ans, i + 1);
            }
            return ans;
        }
    };

    void run_test() {
        Solution solution;
        vector<vector<int>> test = {
            { 2, 2, 1, 1, 5, 3, 3, 5 },
            { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5 }
        };
        for (auto& test_case : test)
            cout << solution.maxEqualFreq(test_case) << endl;
    }
}