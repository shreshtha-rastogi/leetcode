#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long currentMass = mass;

        for (int asteroid : asteroids) {
            if (currentMass < asteroid) {
                return false;
            }
            currentMass += asteroid;
        }

        return true;
    }
};

int main() {
    int mass, n;

    cout << "Enter planet mass: ";
    cin >> mass;

    cout << "Enter number of asteroids: ";
    cin >> n;

    vector<int> asteroids(n);

    cout << "Enter asteroid masses: ";
    for (int i = 0; i < n; i++) {
        cin >> asteroids[i];
    }

    Solution obj;

    if (obj.asteroidsDestroyed(mass, asteroids)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}










