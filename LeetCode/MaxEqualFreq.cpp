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
            // count[i] = j ��ʾ�� i ������ j ��
            // freq[i] = j ��ʾ���ִ���Ϊ i �������� j ��
            unordered_map<int, int> count, freq;
            int max_count = 0, ans = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (count[nums[i]]) --freq[count[nums[i]]];
                max_count = std::max(max_count, ++count[nums[i]]);
                ++freq[count[nums[i]]];
                // �������
                // 1. �����ִ����� 1.
                // 2. �������ĳ��ִ�����Ϊ max_count - 1, ֻ��һ���� max_count.
                // 3. ĳһ�����ĳ��ִ����� 1, ������ max_count.
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