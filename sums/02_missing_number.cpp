/**

You are given all numbers between 1,2,\ldots,n except one. Your task is to find the missing number.
    Input
The first input line contains an integer n.
    The second line contains n-1 numbers. Each number is distinct and between 1 and n (inclusive).
    Output
Print the missing number.
    Constraints

2 \le n \le 2 \cdot 10^5

Example
Input:
    5
2 3 1 5

Output:
    4
**/

// Solution
// The sum of numbers 1,2,\ldots,n is n(n+1)/2. We can calculate the sum of the given numbers and subtract it from the sum of all numbers.
// The time complexity is O(n).
// Implementation

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << n * (n + 1) / 2 - sum << "\n";
    return 0;
}
