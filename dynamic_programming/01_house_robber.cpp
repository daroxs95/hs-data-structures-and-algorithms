/**
https://leetcode.com/problems/house-robber/

House Robber - prefix (backwards)
index from 1
f(0) = 0
f(1) = a[1]
f(i) = max(a[i] + f(i - 2), f(i - 1))

ans = f(n)

 - suffix (forwards)
i -> i + 2 ... n
not i -> i + 1 ...  n

g(i) = max(a[i] + g(i + 2), g(i + 1))
g(n + 1) = 0
g(n) = a[n]
ans = g(1)

 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n + 2);
        dp[n] = nums[n - 1];
        dp[n + 1] = 0;
        for (int i = n - 1; i > 0; --i) {
            dp[i] = max(dp[i + 1], dp[i + 2] + nums[i - 1]);
        }
        return dp[1];
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.rob(nums) << endl;
    return 0;
}