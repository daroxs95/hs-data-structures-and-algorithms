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

    map<int, int> presenceMap;

    for (int i = 0; i < n; ++i) {
        auto item = presenceMap.find(x - a[i]);
        if (item != presenceMap.end()) {
            cout << i+1 << " " << item->second +1 << "\n";
            return 0;
        }
        presenceMap[a[i]] = i;
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}