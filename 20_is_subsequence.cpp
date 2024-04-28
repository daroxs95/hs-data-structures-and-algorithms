// NOT DONE
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    long long tl = 0, tr = t.size() - 1;
    long long sl = 0, sr = s.size() - 1;

    while (tl < tr) {
        if (t[tl] == s[sl]) {
            if (t[tr] == s[sr]) {
                sl++;
                tl++;
                sr--;
            }
            tr--;
            continue;
        }

        if (t[tr] == s[sr]) {
            tl++;
        }
        tr--;
    }

    cout << (sl == sr and t[tl] == s[sl] and t[tr] == s[sr] ? "true" : "false");

    return 0;
}