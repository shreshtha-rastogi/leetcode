#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if (n == 1)
            return 0;

        unordered_map<int, vector<int>> mp;

        // Store all indices for each value
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int curr = q.front();
                q.pop();

                // Reached last index
                if (curr == n - 1)
                    return steps;

                // Move to curr - 1
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }

                // Move to curr + 1
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }

                // Move to all same-value indices
                for (int next : mp[arr[curr]]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }

                // Important optimization
                mp[arr[curr]].clear();
            }

            steps++;
        }

        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};

    cout << obj.minJumps(arr) << endl;

    return 0;
}




