#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        
        for (auto &row : grid) {
            for (auto &val : row) {
                v.push_back(val);
            }
        }
        
        int rem = v[0] % x;
        for (int num : v) {
            if (num % x != rem) return -1;
        }
        
        sort(v.begin(), v.end());
        
        int n = v.size();
        int median = v[n / 2];
        
        int operations = 0;
        for (int num : v) {
            operations += abs(num - median) / x;
        }
        
        return operations;
    }
};










