#include <bits/stdc++.h>

using namespace std;


bool solve(int a, int b) {
    if (a == b) {
        return true;
    }
    int min = a;
    int max = b;
    if (a > b) {
        min = b;
        max = a;
    }

    while (max > min) {
        max = max / 2;
    }

    return max == min;
};

int main() {
    int t;
    cin >> t;
    vector<pair<int, int>> cases(t);
    for (int i = 0; i < t; ++i) {
        cin >> cases[i].first >> cases[i].second;
    }

//    for (auto i: cases) {
//        cout << i.first << " " << i.second;
//    }
//    cout << "\n";

    for (auto c: cases) {
        cout << (solve(c.first, c.second) ? "YES" : "NO") << "\n";
    }

    return 0;
}