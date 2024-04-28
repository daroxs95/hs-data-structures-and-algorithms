#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int cnt;

void permute(string s, int l, int r, set<string> &permutations) r{
    if (l == r) {
        cnt++;
        permutations.insert(s);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permute(s, l + 1, r, permutations);
        swap(s[l], s[i]);
    }
}

int main() {
    string s;
    cin >> s;
    set<string> permutations;
    permute(s, 0, s.size() - 1, permutations);
    cout << permutations.size() << "\n";
    for (auto p: permutations) {
        cout << p << "\n";
    }
    cerr << cnt << endl;
    return 0;
}
