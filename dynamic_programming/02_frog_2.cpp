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
i, jump to one of the following: Stone
i+1,i+2,…,i+K. Here, a cost of
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

1≤K≤100
1≤h
i
​
 ≤10
4
 */
#include <vector>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;


int jump(vector<int> &nums, int steps) {
    int n = nums.size();
    vector<int> dp(n);
    dp[n - 1] = 0;
    dp[n - 2] = abs(nums[n - 1] - nums[n - 2]);
    for (int i = n - 3; i >= 0; --i) {
        int min_cost = INT_MAX;
        for (int j = 1; j <= steps; ++j) {
            if (i + j < n) {
                min_cost = min(min_cost, abs(nums[i + j] - nums[i]) + dp[i + j]);
            }
        }
        dp[i] = min_cost;
    }
    return dp[0];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << jump(a, min(n, k)) << endl;
    return 0;
}