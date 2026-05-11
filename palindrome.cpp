#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPalindrome(string &s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool palindromePair(vector<string>& arr) {

        unordered_map<string, int> mp;

        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
        }

        for(int i = 0; i < arr.size(); i++) {

            string s = arr[i];

            for(int j = 0; j <= s.size(); j++) {

                string left = s.substr(0, j);
                string right = s.substr(j);

                // If left part is palindrome
                if(isPalindrome(left, 0, left.size() - 1)) {

                    string rev = right;
                    reverse(rev.begin(), rev.end());

                    if(mp.count(rev) && mp[rev] != i)
                        return true;
                }

                // If right part is palindrome
                if(j != s.size() && isPalindrome(right, 0, right.size() - 1)) {

                    string rev = left;
                    reverse(rev.begin(), rev.end());

                    if(mp.count(rev) && mp[rev] != i)
                        return true;
                }
            }
        }

        return false;
    }
};

int main() {

    int n;
    cin >> n;

    vector<string> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    if(obj.palindromePair(arr))
        cout << "true";
    else
        cout << "false";

    return 0;
}








