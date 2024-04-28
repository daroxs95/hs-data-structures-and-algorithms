/**
Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.
Input
The first input line has two integers n and m: the number of computers and connections. The computers are numbered 1,2,\dots,n. Uolevi's computer is 1 and Maija's computer is n.
Then, there are m lines describing the connections. Each line has two integers a and b: there is a connection between those computers.
Every connection is between two different computers, and there is at most one connection between any two computers.
Output
If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such a route. You can print any valid solution.
If there are no routes, print "IMPOSSIBLE".
Constraints

2 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5
 **/

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
