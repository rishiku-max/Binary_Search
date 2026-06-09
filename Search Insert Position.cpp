#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LEETCODE 35: Search Insert Position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if( target < nums[0]) return 0;
        if( target > nums[n-1]) return n;
        int lo = 0; int hi = n-1; int idx = -1;
        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) hi = mid-1;
            else lo = mid + 1;
        }
        return lo;
    }
};


int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int target;
    cin>>target;

    Solution obj;

    int result = obj.minimumTime(nums, target);

    cout << result << endl;

    return 0;
}
