#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;

        int reachable = 0;

        for (int i = 1; i < n; i++) {
            if (i >= minJump) {
                reachable += dp[i - minJump];
            }

            if (i > maxJump) {
                reachable -= dp[i - maxJump - 1];
            }

            dp[i] = (reachable > 0 && s[i] == '0');
        }

        return dp[n - 1];
    }
};

int main() {
    Solution sol;

    string s = "011010";
    int minJump = 2, maxJump = 3;

    if (sol.canReach(s, minJump, maxJump))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}




