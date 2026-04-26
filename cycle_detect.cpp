#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        int i = 0, j = 0, k = 0;
        vector<int> ans;

        while(i < a.size() && j < b.size() && k < c.size()) {
            if(a[i] == b[j] && b[j] == c[k]) {
                if(ans.empty() || ans.back() != a[i])
                    ans.push_back(a[i]);
                i++; j++; k++;
            }
            else if(a[i] < b[j]) i++;
            else if(b[j] < c[k]) j++;
            else k++;
        }

        return ans;
    }
};

int main() {
    vector<int> a = {1, 5, 10, 20, 40, 80};
    vector<int> b = {6, 7, 20, 80, 100};
    vector<int> c = {3, 4, 15, 20, 30, 70, 80, 120};

    Solution obj;
    vector<int> result = obj.commonElements(a, b, c);

    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}












