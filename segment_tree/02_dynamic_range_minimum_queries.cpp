#include <vector>
#include <iostream>
#include <climits>

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
        return  lres + rres;
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
            tree[node] = tree[2 * node] + tree[2 * node + 1]; // Change this line for different operations
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
    Node(const long long int i = 0) {
        value = i;
    }

    long long value;

    Node operator+(const Node &other) const {
        Node result;
        result.value = min(this->value, other.value);
        return result;
    }

    Node &operator=(const Node &other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<Node> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].value;
    }

    SegmentTree<Node> st(arr, Node(LLONG_MAX));

    int operation, a, b;
    for (int i = 0; i < q; ++i) {
        cin >> operation >> a >> b;
        if (operation == 1) {
            st.update(a - 1, Node(b));
        } else {
            cout << st.query(a - 1, b - 1).value << endl;
        }
    }

    return 0;
}