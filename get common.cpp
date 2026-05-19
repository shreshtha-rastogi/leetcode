#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {1, 2, 3, 6};
    vector<int> nums2 = {2, 3, 4, 5};

    int ans = obj.getCommon(nums1, nums2);

    cout << "Minimum Common Value: " << ans << endl;

    return 0;
}








