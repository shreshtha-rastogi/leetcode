#include <iostream>
using namespace std;

class Solution {
public:
    bool isGood(int x) {
        bool diff = false;

        while (x > 0) {
            int d = x % 10;

            // invalid digits
            if (d == 3 || d == 4 || d == 7) return false;

            // digits that change after rotation
            if (d == 2 || d == 5 || d == 6 || d == 9)
                diff = true;

            x /= 10;
        }

        return diff;
    }

    int rotatedDigits(int n) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (isGood(i))
                count++;
        }

        return count;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    Solution obj;
    cout << "Number of good integers: " << obj.rotatedDigits(n) << endl;
    return 0;
}