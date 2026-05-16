#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSmallest(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        long long res = 1;
        for (int x : arr) {
            if (x > res)
                break;
            res += x;
        }
        return res;
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

    cout << obj.findSmallest(arr);

    return 0;
}