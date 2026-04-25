#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> a;
        long long P = 4LL * side;

        for (auto &p : points) {
            long long x = p[0], y = p[1];
            if (y == 0) a.push_back(x);
            else if (x == side) a.push_back(side + y);
            else if (y == side) a.push_back(3LL * side - x);
            else a.push_back(4LL * side - y);
        }

        sort(a.begin(), a.end());
        int n = a.size();

        vector<long long> b = a;
        for (auto &x : a) b.push_back(x + P);

        auto can = [&](long long d) {
            for (int i = 0; i < n; i++) {
                long long last = b[i];
                int cnt = 1, pos = i;

                while (cnt < k) {
                    auto it = lower_bound(b.begin() + pos + 1, b.begin() + i + n, last + d);
                    if (it == b.begin() + i + n) break;
                    last = *it;
                    pos = it - b.begin();
                    cnt++;
                }

                if (cnt == k && last - b[i] <= P - d) return true;
            }
            return false;
        };

        long long l = 0, r = 2LL * side, ans = 0;

        while (l <= r) {
            long long mid = (l + r) / 2;
            if (can(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    int side = 2;
    vector<vector<int>> points = {{0,2},{2,0},{2,2},{0,0}};
    int k = 4;

    cout << sol.maxDistance(side, points, k) << endl;

    return 0;
}








