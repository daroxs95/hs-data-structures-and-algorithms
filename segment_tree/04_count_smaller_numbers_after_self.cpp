#include <vector>
#include <iostream>
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

class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans = vector<int>(n, 0);
        auto values = nums;
        sort(values.begin(), values.end());
        values.resize(unique(values.begin(), values.end()) - values.begin());

        map<int, int> compression_map;
        for (int i = 0; i < values.size(); ++i) {
            compression_map[values[i]] = i;
        }

        vector<Node> freq(values.size(), Node(0));

        SegmentTree<Node> st(freq, Node(0));

        for (int i = n - 1; i >= 0; --i) {
            auto index = compression_map[nums[i]];

            ans[i] = st.query(0, index - 1).sum;
            st.update(index, Node(freq[index].sum + 1));
            freq[index].sum++;
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a = {5, 2, 6, 1};
    Solution solution;
    auto ans = solution.countSmaller(a);
    for (auto i: ans) {
        cout << i << " ";
    }

    return 0;
}