#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long lcm(long long a, long long b) {
        return (a / __gcd(a, b)) * b;
    }

    void build(int node, int start, int end, vector<long long>& seg, vector<int>& arr) {

        if (start == end) {
            seg[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        build(2 * node, start, mid, seg, arr);
        build(2 * node + 1, mid + 1, end, seg, arr);

        seg[node] = lcm(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val, vector<long long>& seg) {

        if (start == end) {
            seg[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(2 * node, start, mid, idx, val, seg);
        else
            update(2 * node + 1, mid + 1, end, idx, val, seg);

        seg[node] = lcm(seg[2 * node], seg[2 * node + 1]);
    }

    long long query(int node, int start, int end, int l, int r, vector<long long>& seg) {

        if (r < start || end < l)
            return 1;

        if (l <= start && end <= r)
            return seg[node];

        int mid = (start + end) / 2;

        long long left = query(2 * node, start, mid, l, r, seg);
        long long right = query(2 * node + 1, mid + 1, end, l, r, seg);

        return lcm(left, right);
    }

    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {

        int n = arr.size();

        vector<long long> seg(4 * n);

        build(1, 0, n - 1, seg, arr);

        vector<long long> ans;

        for (auto &q : queries) {

            if (q[0] == 1) {

                int idx = q[1];
                int val = q[2];

                update(1, 0, n - 1, idx, val, seg);
            }
            else {

                int l = q[1];
                int r = q[2];

                ans.push_back(query(1, 0, n - 1, l, r, seg));
            }
        }

        return ans;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(3));

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    Solution obj;

    vector<long long> ans = obj.RangeLCMQuery(arr, queries);

    for (auto x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}










