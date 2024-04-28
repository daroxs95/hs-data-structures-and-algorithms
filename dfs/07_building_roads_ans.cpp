#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, const vector <vector<int>> &adj, vector<bool> &visited, vector<int> &component) {
    visited[node] = true;
    component.push_back(node);
    for (auto x: adj[node]) {
        if (!visited[x]) {
            dfs(x, adj, visited, component);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector <vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n + 1);
    vector <vector<int>> components;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components.push_back(vector<int>());
            dfs(i, adj, visited, components.back());
        }
    }

    cout << components.size() - 1 << "\n";

    for (int i = 1; i < components.size(); i++) {
        cout << components[0][0] << " " << components[i][0] << "\n";
    }

    return 0;
}