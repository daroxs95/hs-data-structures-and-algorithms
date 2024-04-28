#include <bits/stdc++.h>

using namespace std;

// TODO: add summable trait
template<typename TNode>
struct SegmentTree {
    vector<TNode> tree;
    TNode neutral;
    int n;

private:
    void build(const vector<TNode> &a, int node, int start, int end) {
        if (start == end) {
            tree[node] = a[start];
        } else {
            int mid = (start + end) / 2;
            build(a, 2 * node, start, mid);
            build(a, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    TNode query(int node, int start, int end, int left, int right) {
        if (right < start || left > end) return neutral;
        if (left <= start && right >= end) return tree[node];
        int mid = (start + end) / 2;
        auto lres = query(2 * node, start, mid, left, right);
        auto rres = query(2 * node + 1, mid + 1, end, left, right);
        return lres + rres;
    }

    void update(int node, int start, int end, int idx, TNode val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

public:
    explicit SegmentTree(const vector<TNode> &a, const TNode neutral) {
        n = a.size();
        tree.resize(4 * n);
        this->neutral = neutral;
        build(a, 1, 0, n - 1);
    }

    TNode query(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }

    void update(int idx, TNode val) {
        update(1, 0, n - 1, idx, val);
    }
};

struct Node {
    Node(const int v = 0) {
        sum = v;
    }

    int sum;

    Node operator+(const Node &other) const {
        Node result;
        result.sum = this->sum + other.sum;
        return result;
    }

    Node &operator=(const Node &other) {
        if (this != &other) {
            sum = other.sum;
        }
        return *this;
    }
};


int main() {
    int n, q;
    cin >> n >> q;

    vector<Node> input(n);
    for (int i = 0; i < input.size(); ++i) {
        cin >> input[i].sum;
    }

    SegmentTree<Node> st(input, Node(0));

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            input[b].sum = input[b].sum == 1 ? 0 : 1;
            st.update(b, input[b]);
            continue;
        }
        int pos = -1;

        if (b == 0) {
            pos = 0;
            cout << pos << "\n";
            continue;
        }
        for (int j = b - 1; j < input.size(); ++j) {
            if (st.query(0, j).sum == b) {
                pos = j;
                break;
            }
        }
        cout << pos << "\n";
    }

    return 0;
}