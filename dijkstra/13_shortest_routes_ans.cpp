#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Node {
    long long vertex, marked_dist, prev;
};

struct PathTo {
    long long node, dist;
};

struct CompareNode {
    bool operator()(const Node &lhs, const Node &rhs) {
        return lhs.marked_dist > rhs.marked_dist;
    }
};

void djkstra(Node &start, const vector<vector<PathTo>> &adj, vector<Node> &nodes) {
    vector<bool> visited(nodes.size(), false);
    priority_queue<Node, vector<Node>, CompareNode> pq;
    start.marked_dist = 0;
    pq.push(start);
    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        if (visited[current.vertex]) continue;
        visited[current.vertex] = true;
        for (auto path_to: adj[current.vertex]) {
            if (nodes[path_to.node].marked_dist <= nodes[current.vertex].marked_dist + path_to.dist) continue;
            nodes[path_to.node].marked_dist = nodes[current.vertex].marked_dist + path_to.dist;
            nodes[path_to.node].prev = current.vertex;
            pq.push({path_to.node, nodes[path_to.node].marked_dist, current.vertex});
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<PathTo>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
//        adj[b].push_back({a, c});
    }

    vector<Node> nodes(n, {0, LLONG_MAX, -1});
    for (int i = 0; i < n; i++) {
        nodes[i].vertex = i;
    }

    djkstra(nodes[0], adj, nodes);

    for (auto node: nodes) {
        cout << node.marked_dist << " ";
    }

    return 0;
}