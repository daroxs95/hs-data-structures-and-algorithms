#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int where[n];
    for (int i = 0; i < n; i++) {
        where[a[i]] = i;
    }

    long long rounds = 1;
    for (int i = 1; i < n; i++) {
        if (where[i] > where[i + 1]) {
            rounds++;
        }
    }

    cout << rounds << "\n";

    return 0;
}