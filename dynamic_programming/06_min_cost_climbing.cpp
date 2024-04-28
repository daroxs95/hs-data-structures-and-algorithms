//https://leetcode.com/problems/min-cost-climbing-stairs/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[n] = 0;
        dp[n - 1] = cost[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            dp[i] = min(dp[i + 1], dp[i + 2]) + cost[i];
        }

        return min(dp[0], dp[1]);
    }
};

int main() {
    vector<int> cost = {10, 15, 20};
    Solution s;
    cout << s.minCostClimbingStairs(cost) << endl;
    return 0;
}