#include <iostream>
#include <vector>

using namespace std;

long long kadane(const vector<long long> a) {
    long long max_sum = a[0];
    long long best_sum = a[0];
    for (int i = 1; i < a.size(); i++) {
        max_sum = max(a[i], max_sum + a[i]);
        best_sum = max(max_sum, best_sum);
    }
    return best_sum;
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << kadane(a) << "\n";

    return 0;
}