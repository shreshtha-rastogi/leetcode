#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum = 0, F = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += (long long)i * nums[i];
        }
        
        long long ans = F;
        
        for (int k = 1; k < n; k++) {
            F = F + sum - (long long)n * nums[n - k];
            ans = max(ans, F);
        }
        
        return ans;
    }
};

int main() {
    Solution obj;
    
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << obj.maxRotateFunction(nums) << endl;
    
    return 0;
}











