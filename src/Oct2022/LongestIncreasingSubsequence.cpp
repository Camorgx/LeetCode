// https://leetcode.cn/problems/longest-increasing-subsequence/

#include <iostream>
#include <vector>

#pragma warning(disable : 6385)
#pragma warning(disable : 6386)

namespace LongestIncreasingSubsequence {
    using std::cout, std::endl;
    using std::vector;

    class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            if (nums.empty()) return 0;
            int* d = new int[nums.size()];
            int len = 1;
            d[len - 1] = nums[0];
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] > d[len - 1]) d[len++] = nums[i];
                else {
                    auto pos = std::lower_bound(d, d + len, nums[i]);
                    if (pos == d + len) d[0] = nums[i];
                    else
                        *pos = nums[i];
                }
            }
            delete[] d;
            return len;
        }
    };

    void runTest() {
        vector<vector<int>> tests = {
                {10, 9, 2, 5, 3, 7, 101, 18},
                {0,  1, 0, 3, 2, 3},
                {7,  7, 7, 7, 7, 7, 7}};
        Solution solution;
        for (auto& test: tests)
            cout << solution.lengthOfLIS(test) << endl;
    }
}// namespace LongestIncreasingSubsequence