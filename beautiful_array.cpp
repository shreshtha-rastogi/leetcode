#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int> st;

        for (int x : arr) {
            // If adjacent elements have opposite signs
            if (!st.empty() &&
               ((st.back() >= 0 && x < 0) ||
                (st.back() < 0 && x >= 0))) {
                
                st.pop_back();
            }
            else {
                st.push_back(x);
            }
        }

        return st;
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
    vector<int> ans = obj.makeBeautiful(arr);

    if (ans.empty()) {
        cout << "[]";
    } else {
        for (int x : ans) {
            cout << x << " ";
        }
    }

    return 0;
}






