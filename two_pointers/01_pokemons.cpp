//https://codeforces.com/problemset/problem/701/C

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    auto temp_s = s;
    sort(temp_s.begin(), temp_s.end());
    int alphabet_size = unique(temp_s.begin(), temp_s.end()) - temp_s.begin();

    int r = 0, l = 0, min_flats = n;
    vector<int> ocurrences(256, 0);
    int different_chars_count = 0;

    while (different_chars_count < alphabet_size) {
        ocurrences[s[r]]++;
        if (ocurrences[s[r]] == 1) {
            different_chars_count++;
        }
        r++;
    }

    r--;

    for (; r < s.size(); ++r) {
        while (l < r and ocurrences[s[l]] > 1) {
            ocurrences[s[l]]--;
            l++;
        }
        min_flats = min(min_flats, r - l + 1);
        ocurrences[s[r+1]]++;
    }

    cout << min_flats << endl;

    return 0;
}