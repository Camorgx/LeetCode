// https://leetcode.cn/problems/maximum-equal-frequency/

#include <iostream>
#include <unordered_map>
#include <vector>

namespace MaxEqualFreq {
    using std::cout, std::endl;
    using std::unordered_map;
    using std::vector;

    class Solution {
    public:
        int maxEqualFreq(vector<int>& nums) {
            // count[i] = j means number i showed j times
            // freq[i] = j means there are j numbers showing up i times
            unordered_map<int, int> count, freq;
            int max_count = 0, ans = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (count[nums[i]]) --freq[count[nums[i]]];
                max_count = std::max(max_count, ++count[nums[i]]);
                ++freq[count[nums[i]]];
                // Only 3 situations
                // 1. Showing up no more than 1 time.
                // 2. Every other number shows up max_count - 1 times, except one max_count times.
                // 3. A certain number shows up 1 time, while the others max_count.
                if (max_count == 1
                    || (freq[max_count] == 1 && (max_count - 1) * freq[max_count - 1] + max_count == i + 1)
                    || (freq[1] == 1 && freq[max_count] * max_count + 1 == i + 1))
                    ans = std::max(ans, i + 1);
            }
            return ans;
        }
    };

    void run_test() {
        Solution solution;
        vector<vector<int>> test = {
                {2, 2, 1, 1, 5, 3, 3, 5},
                {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5}};
        for (auto& test_case: test)
            cout << solution.maxEqualFreq(test_case) << endl;
    }
}// namespace MaxEqualFreq