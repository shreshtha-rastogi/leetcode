#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> dp;
    vector<int> a;

    int dfs(int i, int d) {
        if (dp[i] != -1) return dp[i];

        int best = 1;

        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
            if (a[j] >= a[i]) break;
            best = max(best, 1 + dfs(j, d));
        }

        for (int j = i - 1; j >= max(0, i - d); j--) {
            if (a[j] >= a[i]) break;
            best = max(best, 1 + dfs(j, d));
        }

        return dp[i] = best;
    }

    int maxJumps(vector<int>& arr, int d) {
        a = arr;
        n = arr.size();
        dp.assign(n, -1);

        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, d));
        }
        return ans;
    }
};
















