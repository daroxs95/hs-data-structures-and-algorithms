//https://leetcode.com/problems/minimum-path-sum/description/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long solve(vector<pair<int, int>> &data, int tw) {
    int n = data.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(tw + 1, 0LL));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= tw; ++j) {
            if (j >= data[i - 1].second) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - data[i - 1].second] + data[i - 1].first);
                continue;
            }
            dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][tw];
}

long long get_max_benefit(int i, int tw, vector<pair<int,int>> &data, vector<vector<long long>> &memo){

    if(i == 0){
        return 0;
    }

    if(memo[i][tw] != -1){
        return memo[i][tw];
    }

    long long result = get_max_benefit(i - 1, tw, data, memo); // ignore the i-th item
    if(data[i - 1].second <= tw){ // take the i-th item
        result = max(result,
                     get_max_benefit(i - 1, tw - data[i - 1].second, data, memo) + data[i - 1].first);
    }

    memo[i][tw] = result;

    return result;
}

int main() {
    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> input(n);

    for (auto &[f, s]: input) {
        cin >> s >> f;
    }

    vector<vector<long long>> memo(n + 1, vector<long long>(w + 1, -1ll));

    cout << get_max_benefit(n, w, input, memo) << endl;
//    cout << solve(input, w) << endl;
    return 0;
}