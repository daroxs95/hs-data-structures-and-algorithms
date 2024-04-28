#include <iostream>
#include <vector>

using namespace std;


int dfs(int node, const vector<vector<int>> &adj, vector<bool> &visited) {
    int last = node;
    visited[node] = true;
    for (auto x: adj[node]) {
        if (visited[x]) {
            break;
        }
        auto nl = dfs(x, adj, visited);
        last = nl == -1 ? node : nl;
    }
    return last;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        adj[i].push_back(x);
    }

    for (int start_city = 1; start_city <= n; start_city++) {
        vector<bool> visited(n + 1, false);
        cout << adj[dfs(start_city, adj, visited)][0] << " ";
    }

    return 0;
}