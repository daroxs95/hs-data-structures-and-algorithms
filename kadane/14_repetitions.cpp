#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int answer = 1;
    int count = 1;
    for (int i = 1; i < s.size(); i++) {
        count = s[i] == s[i - 1] ? count + 1 : 1;
        answer = max(answer, count);
    }
    cout << answer << "\n";
    return 0;
}