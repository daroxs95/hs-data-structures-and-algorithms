#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <map>

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
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> input(n), all_values;
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
        all_values.push_back(input[i]);
    }
    vector<pair<char, pair<int, int>>> queries;
    char operation;
    int a, b;
    for (int i = 0; i < q; ++i) {
        cin >> operation >> a >> b;
        queries.push_back({operation, {a, b}});

        // Keeping track of all possible values, including the ones that are not in the input at start
        all_values.push_back(b);
        if (operation == '?') {
            // for avoiding doing binary search on all_values
            all_values.push_back(a);
        }
    }

    sort(all_values.begin(), all_values.end());
    all_values.resize(unique(all_values.begin(), all_values.end()) - all_values.begin());

    map<int, int> compression_map;
    for (int i = 0; i < all_values.size(); ++i) {
        compression_map[all_values[i]] = i;
    }

    // Creating frequency array
    vector<Node> freq(all_values.size(), Node(0));
    for (auto i: input) {
        freq[compression_map[i]].sum++;
    }

    SegmentTree<Node> st(freq, Node(0));

    for (auto &query: queries) {
        if (query.first == '!') {
            auto old_value = compression_map[input[query.second.first - 1]];
            auto new_value = compression_map[query.second.second];

            st.update(old_value, Node(freq[old_value].sum - 1));
            st.update(new_value, Node(freq[new_value].sum + 1));

            freq[old_value].sum--;
            freq[new_value].sum++;

            input[query.second.first - 1] = query.second.second;
        } else {
            cout << st.query(compression_map[query.second.first], compression_map[query.second.second]).sum
                 << '\n';
        }
    }

    return 0;
}