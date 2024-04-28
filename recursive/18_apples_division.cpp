#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long min_difference(const vector<long long> &weights, int i, long long g1_sum, long long g2_sum) {
    if (i == weights.size()) {
        return abs(g1_sum - g2_sum);
    }
    long long diff1 = min_difference(weights, i + 1, g1_sum + weights[i], g2_sum);
    long long diff2 = min_difference(weights, i + 1, g1_sum, g2_sum + weights[i]);
    return min(diff1, diff2);
}

int main() {
    int n;
    cin >> n;

    vector<long long> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    long long min = min_difference(weights, 0, 0, 0);
    cout << min << endl;

    return 0;
}
