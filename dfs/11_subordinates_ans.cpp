#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs(int node, map<int, vector<int>> &adj, vector<int> &subordinates) {
    for (int child: adj[node]) {
        dfs(child, adj, subordinates);
        subordinates[node] += subordinates[child] + 1;
    }
}

int main() {
    int n;
    cin >> n;
    map<int, vector<int>> adj;
    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }

    vector<int> subordinates(n + 1);
    dfs(1, adj, subordinates);

    for (int i = 1; i <= n; i++) {
        cout << subordinates[i] << " ";
    }
    cout << "\n";

    return 0;
}