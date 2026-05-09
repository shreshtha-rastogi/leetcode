#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long determinant(vector<vector<long long>> mat, int n) {
        long long det = 1;

        for (int i = 0; i < n; i++) {
            int pivot = i;

            while (pivot < n && mat[pivot][i] == 0)
                pivot++;

            if (pivot == n)
                return 0;

            if (pivot != i) {
                swap(mat[pivot], mat[i]);
                det *= -1;
            }

            for (int j = i + 1; j < n; j++) {
                while (mat[j][i] != 0) {
                    long long t = mat[i][i] / mat[j][i];

                    for (int k = i; k < n; k++) {
                        mat[i][k] -= t * mat[j][k];
                    }

                    swap(mat[i], mat[j]);
                    det *= -1;
                }
            }

            det *= mat[i][i];
        }

        return abs(det);
    }

    int countSpanTree(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return 1;

        vector<vector<long long>> lap(n, vector<long long>(n, 0));

        for (auto &e : edges) {
            lap[e[0]][e[0]]++;
            lap[e[1]][e[1]]++;

            lap[e[0]][e[1]]--;
            lap[e[1]][e[0]]--;
        }

        vector<vector<long long>> minor(n - 1, vector<long long>(n - 1));

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                minor[i][j] = lap[i][j];
            }
        }

        return (int)determinant(minor, n - 1);
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;

    cout << obj.countSpanTree(n, edges) << endl;

    return 0;
}




























