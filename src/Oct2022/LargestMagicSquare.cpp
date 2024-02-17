#include <iostream>
#include <vector>

namespace LargestMagicSquare {
    // https://leetcode.cn/problems/largest-magic-square/

    using std::cout, std::endl;
    using std::vector;

    class Solution {
    public:
        int largestMagicSquare(vector<vector<int>>& grid) {
            // m lines, n rows
            size_t m = grid.size(), n = grid[0].size();

            vector<vector<int>> sum(m, vector<int>(n));
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    sum[i][j] = grid[i][j]
                                + (i == 0 ? 0 : sum[i - 1][j])
                                + (j == 0 ? 0 : sum[i][j - 1])
                                - (i && j ? sum[i - 1][j - 1] : 0);

            int ans = static_cast<int>(std::min(m, n));
            for (; ans >= 1; --ans) {
                for (int i = 0; i <= m - ans; ++i)
                    for (int j = 0; j <= n - ans; ++j) {
                        int line_sum = sum[i][j + ans - 1]
                                       - (i == 0 ? 0 : sum[i - 1][j + ans - 1])
                                       - (j == 0 ? 0 : sum[i][j - 1])
                                       + (i && j ? sum[i - 1][j - 1] : 0);
                        int left_cross = 0, right_cross = 0;
                        for (int k = 0; k < ans; ++k) {
                            int x = i + k, y = j + k;
                            int line = sum[x][j + ans - 1]
                                       - (x == 0 ? 0 : sum[x - 1][j + ans - 1])
                                       - (j == 0 ? 0 : sum[x][j - 1])
                                       + (x && j ? sum[x - 1][j - 1] : 0);
                            int row = sum[i + ans - 1][y]
                                      - (y == 0 ? 0 : sum[i + ans - 1][y - 1])
                                      - (i == 0 ? 0 : sum[i - 1][y])
                                      + (i && y ? sum[i - 1][y - 1] : 0);
                            left_cross += grid[x][y];
                            right_cross += grid[x][j + ans - k - 1];
                            if (line != line_sum || row != line_sum) goto next_loop;
                        }
                        if (left_cross == line_sum && right_cross == line_sum)
                            goto print_ans;
                        next_loop:;
                    }
            }
            print_ans:
            return ans;
        }
    };

    void runTest() {
        Solution solution;
        vector<vector<int>> test = {
                {7, 1, 4, 5, 6},
                {2, 5, 1, 6, 4},
                {1, 5, 4, 3, 2},
                {1, 2, 7, 3, 4}};
        int ans = solution.largestMagicSquare(test);
        cout << ans << endl;
    }
}// namespace LargestMagicSquare