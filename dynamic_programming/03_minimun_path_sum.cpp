//https://leetcode.com/problems/minimum-path-sum/description/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
        dp[n - 1][m - 1] = grid[n - 1][m - 1];
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if(i == n - 1 and j == m - 1){
                    continue;
                }
                dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) + grid[i][j];
            }
        }
        return dp[0][0];
    }
};

int main() {
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    Solution s;
    cout << s.minPathSum(grid) << endl;
    return 0;
}