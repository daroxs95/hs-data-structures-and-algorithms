// https://atcoder.jp/contests/dp/tasks/dp_a
/**
Problem Statement
There are
N stones, numbered
1,2,…,N. For each
i (
1≤i≤N), the height of Stone
i is
h
i
​
 .

There is a frog who is initially on Stone
1. He will repeat the following action some number of times to reach Stone
N:

If the frog is currently on Stone
i, jump to Stone
i+1 or Stone
i+2. Here, a cost of
∣h
i
​
 −h
j
​
 ∣ is incurred, where
j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone
N.

Constraints
All values in input are integers.
2≤N≤10
5

1≤h
i
​
 ≤10
4
 */
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


int jump(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n);
    dp[n - 1] = 0;
    dp[n - 2] = abs(nums[n - 1] - nums[n - 2]);
    for (int i = n - 3; i >= 0; --i) {
        dp[i] = min(abs(nums[i + 1] - nums[i]) + dp[i + 1], abs(nums[i + 2] - nums[i]) + dp[i + 2]);
    }
    return dp[0];
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << jump(a) << endl;
    return 0;
}