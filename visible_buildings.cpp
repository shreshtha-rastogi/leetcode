#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        int count = 0;
        int maxHeight = 0;

        for(int h : arr) {
            if(h >= maxHeight) {
                count++;
                maxHeight = h;
            }
        }

        return count;
    }
};

int main() {
    int n;
    cin >> n;   // number of buildings

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.visibleBuildings(arr) << endl;

    return 0;
}






