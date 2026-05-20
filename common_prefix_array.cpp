#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> freq(n + 1, 0);
        vector<int> ans;

        int common = 0;

        for (int i = 0; i < n; i++) {
            freq[A[i]]++;
            if (freq[A[i]] == 2) {
                common++;
            }

            freq[B[i]]++;
            if (freq[B[i]] == 2) {
                common++;
            }

            ans.push_back(common);
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> A(n), B(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    Solution obj;
    vector<int> result = obj.findThePrefixCommonArray(A, B);

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}










