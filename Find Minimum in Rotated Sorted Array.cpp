#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LEETCODE 153: Find Minimum in Rotated Sorted Array


class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0; int hi = nums.size()-1;
        while(lo<hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] > nums[hi]){
                lo = mid+1;
            }
            else {
                hi = mid;
            }
        }
        return nums[lo];
        
    }
};


int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    

    Solution obj;

    int result = obj.findMin(nums);

    cout << result << endl;

    return 0;
}
