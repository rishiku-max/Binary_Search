#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LEETCODE 33: Search in Rotated Sorted Array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n - 1;

        while(lo < hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] > nums[hi])
                lo = mid + 1;
            else
                hi = mid;
        }

        int pivot = lo;
        
        // got the pivot index
        if(nums[pivot] <= target && nums[n-1] >= target){
            lo = pivot; hi = n-1;
            while(lo <= hi){
                int mid = lo + (hi - lo)/2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] > target) hi = mid-1;
                else lo = mid+1;
            }
        } else {
            lo = 0; hi = pivot-1;
            while(lo <= hi){
                int mid = lo + (hi - lo)/2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] > target) hi = mid - 1;
                else lo = mid + 1;
            }
        }
        return -1;
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

    int result = obj.search(nums, target);

    cout << result << endl;

    return 0;
}
