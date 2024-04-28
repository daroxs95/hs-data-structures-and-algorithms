#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }

    long long answers = 0;

    map<long long, long long> presenceMap;
    presenceMap[0] = 1;
    for (int i = 1; i <= n; ++i) {
        answers += presenceMap[prefix[i] - x];
        presenceMap[prefix[i]]++;
    }

    cout << answers << "\n";

    return 0;
}