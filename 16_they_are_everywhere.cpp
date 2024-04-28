//NOT DONE
/**

Sergei B., the young coach of Pokemons, has found the big house which consists of n flats ordered in a row from left to right. It is possible to enter each flat from the street. It is possible to go out from each flat. Also, each flat is connected with the flat to the left and the flat to the right. Flat number 1 is only connected with the flat number 2 and the flat number n is only connected with the flat number n - 1.

There is exactly one Pokemon of some type in each of these flats. Sergei B. asked residents of the house to let him enter their flats in order to catch Pokemons. After consulting the residents of the house decided to let Sergei B. enter one flat from the street, visit several flats and then go out from some flat. But they won't let him visit the same flat more than once.

Sergei B. was very pleased, and now he wants to visit as few flats as possible in order to collect Pokemons of all types that appear in this house. Your task is to help him and determine this minimum number of flats he has to visit.

Input
The first line contains the integer n (1 ≤ n ≤ 100 000) — the number of flats in the house.

The second line contains the row s with the length n, it consists of uppercase and lowercase letters of English alphabet, the i-th letter equals the type of Pokemon, which is in the flat number i.

Output
Print the minimum number of flats which Sergei B. should visit in order to catch Pokemons of all types which there are in the house.

Examples
inputCopy
3
AaA
outputCopy
2
inputCopy
7
bcAAcbc
outputCopy
3
inputCopy
6
aaBCCe
outputCopy
5
Note
In the first test Sergei B. can begin, for example, from the flat number 1 and end in the flat number 2.

In the second test Sergei B. can begin, for example, from the flat number 4 and end in the flat number 6.

In the third test Sergei B. must begin from the flat number 2 and end in the flat number 6.

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> cnt(256);
    int ans = 0;
    int unique = 0;
    for (int i = 0, j = 0; i < n; i++) {
        if (cnt[s[i]] == 0) {
            unique++;
        }
        cnt[s[i]]++;
        while (unique == cnt['a'] + cnt['b'] + cnt['c'] + cnt['d'] + cnt['e'] + cnt['f'] + cnt['g'] + cnt['h'] + cnt['i'] + cnt['j'] + cnt['k'] + cnt['l'] + cnt['m'] + cnt['n'] + cnt['o'] + cnt['p'] + cnt['q'] + cnt['r'] + cnt['s'] + cnt['t'] + cnt['u'] + cnt['v'] + cnt['w'] + cnt['x'] + cnt['y'] + cnt['z'] + cnt['A'] + cnt['B'] + cnt['C'] + cnt['D'] + cnt['E'] + cnt['F'] + cnt['G'] + cnt['H'] + cnt['I'] + cnt['J'] + cnt['K'] + cnt['L'] + cnt['M'] + cnt['N'] + cnt['O'] + cnt['P'] + cnt['Q'] + cnt['R'] + cnt['S'] + cnt['T'] + cnt['U'] + cnt['V'] + cnt['W'] + cnt['X'] + cnt['Y'] + cnt['Z']) {
            cnt[s[j]]--;
            if (cnt[s[j]] == 0) {
                unique--;
            }
            j++;
        }
        ans = max(ans, i - j + 1);
    }

    cout << ans << "\n";

    return 0;
}