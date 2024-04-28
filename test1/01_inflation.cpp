#include <iostream>

using namespace std;

int main() {
    int n, current_price, prev_price = 0, max_streak = 1, streak = 1;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }

    cin >> prev_price;
    for (int i = 1; i < n; i++) {
        cin >> current_price;
        streak = current_price > prev_price ? ++streak : 1;
        max_streak = max(max_streak, streak);
        prev_price = current_price;
    }

    cout << max_streak;

    return 0;
}