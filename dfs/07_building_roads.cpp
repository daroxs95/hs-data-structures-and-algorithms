/**
* Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.
Your task is to find out the minimum number of roads required, and also determine which roads should be built.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.
Output
First print an integer k: the number of required roads.
Then, print k lines that describe the new roads. You can print any valid solution.
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
4 2
1 2
3 4

Output:
1
2 3
*/

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