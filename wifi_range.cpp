#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool wifiRange(string &s, int x) {
        int n = s.size();
        int coveredTill = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                int left = max(0, i - x);

                // Gap found before this router's coverage
                if (left > coveredTill + 1) {
                    return false;
                }

                coveredTill = max(coveredTill, min(n - 1, i + x));
            }
        }

        return coveredTill >= n - 1;
    }
};

int main() {
    Solution obj;

    int x;
    string s;

    cin >> x >> s;

    bool result = obj.wifiRange(s, x);

    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
