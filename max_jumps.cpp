#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        
        int n = nums.size();

        vector<int> dp(n, -1);
        dp[0] = 0;

        for(int i = 0; i < n; i++) {

            if(dp[i] == -1)
                continue;

            for(int j = i + 1; j < n; j++) {

                if(abs(nums[j] - nums[i]) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};

int main() {

    vector<int> nums = {1, 3, 6, 4, 1, 2};
    int target = 2;

    Solution obj;

    cout << obj.maximumJumps(nums, target);

    return 0;
}












