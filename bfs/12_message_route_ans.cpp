#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int node, const vector <vector<int>> &adj, vector<int> &dist, vector<int> &prev) {
    queue<int> q;
    q.push(node);
    dist[node] = 0;
    prev[node] = -1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto y: adj[x]) {
            if (dist[y] == -1) {
                dist[y] = dist[x] + 1;
                prev[y] = x;
                q.push(y);
            }
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

    vector<int> dist(n + 1, -1);
    vector<int> prev(n + 1);
    bfs(1, adj, dist, prev);

    if (dist[n] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dist[n] + 1 << "\n";
    vector<int> route;
    for (int i = n; i != -1; i = prev[i]) {
        route.push_back(i);
    }
    for (int i = route.size() - 1; i >= 0; i--) {
        cout << route[i] << " ";
    }
    cout << "\n";

    return 0;
}
