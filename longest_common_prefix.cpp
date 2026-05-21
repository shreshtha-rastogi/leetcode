#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        
        // Store all prefixes from arr1
        for (int x : arr1) {
            string s = to_string(x);
            string pref = "";
            
            for (char c : s) {
                pref += c;
                st.insert(pref);
            }
        }

        int ans = 0;

        // Check prefixes in arr2
        for (int x : arr2) {
            string s = to_string(x);
            string pref = "";

            for (char c : s) {
                pref += c;

                if (st.count(pref)) {
                    ans = max(ans, (int)pref.size());
                }
            }
        }

        return ans;
    }
};

int main() {
    int n, m;

    cin >> n;
    vector<int> arr1(n);

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cin >> m;
    vector<int> arr2(m);

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    Solution obj;

    cout << obj.longestCommonPrefix(arr1, arr2) << endl;

    return 0;
}