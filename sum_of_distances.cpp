#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<long long> ans(n, 0);
        
        for(auto &it : mp) {
            vector<int> &idx = it.second;
            int k = idx.size();
            
            vector<long long> pref(k, 0);
            pref[0] = idx[0];
            
            for(int i = 1; i < k; i++) {
                pref[i] = pref[i-1] + idx[i];
            }
            
            for(int i = 0; i < k; i++) {
                long long left = (long long)idx[i] * i - (i > 0 ? pref[i-1] : 0);
                long long right = (pref[k-1] - pref[i]) - (long long)idx[i] * (k - i - 1);
                ans[idx[i]] = left + right;
            }
        }
        
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    Solution obj;
    vector<long long> result = obj.distance(nums);
    
    for(long long x : result) {
        cout << x << " ";
    }
    
    return 0;
}






