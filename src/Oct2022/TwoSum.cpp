// https://leetcode.cn/problems/two-sum/

#include <iostream>
#include <vector>

namespace TwoSum {
    using std::cout, std::endl;
    using std::vector;

    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            for (int i = 0; i < nums.size(); ++i)
                for (int j = i + 1; j < nums.size(); ++j)
                    if (nums[i] + nums[j] == target)
                        return vector<int>({i, j});
            return {};
        }
    };

    void run_test() {
        Solution solution;

        vector<int> set1 = {2, 7, 11, 15};
        auto ans1 = solution.twoSum(set1, 9);
        cout << ans1[0] << ' ' << ans1[1] << endl;

        vector<int> set2 = {3, 2, 4};
        auto ans2 = solution.twoSum(set2, 6);
        cout << ans2[0] << ' ' << ans2[1] << endl;

        vector<int> set3 = {3, 3};
        auto ans3 = solution.twoSum(set3, 6);
        cout << ans3[0] << ' ' << ans3[1] << endl;
    }
}// namespace TwoSum