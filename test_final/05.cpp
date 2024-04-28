#include <bits/stdc++.h>

using namespace std;

int solve(const vector<int> &arr, int i, int min_v, const int &max_arr_val, vector<vector<int>> &cache) {
    if (cache[i][min_v] != -1) {
        return cache[i][min_v];
    }

    if (i == arr.size()) {
        int max_days = arr[i] >= min_v ? 1 : 0;
        return cache[i][min_v] = max_days;
    }

    int max_days = solve(arr, i + 1, min_v, max_arr_val, cache);
    for (int j = 0; j < max_arr_val and arr[i] * 2 + j < max_arr_val; ++j) {
        max_days = max(solve(arr, i + 1, arr[i] * 2 + j, max_arr_val, cache) + 1, max_days);
    }

    return cache[i][min_v] = max_days;
}

int main() {
    int n;
    cin >> n;
    vector<int> input(n);

    for (int i = 0; i < input.size(); ++i) {
        cin >> input[i];
    }

    int max_v = input[0];
    for (int i = 1; i < input.size(); ++i) {
        max_v = max(max_v, input[i]);
    }

    vector<vector<int>> cache(n + 5, vector<int>(2 * max_v + 5, -1));

    cout << solve(input, 0, 0, max_v, cache);

    return 0;
}