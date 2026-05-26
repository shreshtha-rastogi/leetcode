#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minToggle(vector<int>& arr) {
        int n = arr.size();

        vector<int> prefixOnes(n + 1, 0);
        vector<int> suffixZeros(n + 1, 0);

        // Count ones in prefix
        for (int i = 0; i < n; i++) {
            prefixOnes[i + 1] = prefixOnes[i] + (arr[i] == 1);
        }

        // Count zeros in suffix
        for (int i = n - 1; i >= 0; i--) {
            suffixZeros[i] = suffixZeros[i + 1] + (arr[i] == 0);
        }

        int ans = INT_MAX;

        // Try every partition point
        for (int i = 0; i <= n; i++) {
            int toggles = prefixOnes[i] + suffixZeros[i];
            ans = min(ans, toggles);
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.minToggle(arr) << endl;

    return 0;
}








