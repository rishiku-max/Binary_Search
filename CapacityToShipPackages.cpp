#include <bits/stdc++.h>
using namespace std;

//LEETCODE 1011: Capacity To Ship Packages Within D Days

class Solution {
public:

    bool check(int mid, vector<int>& weights, int days){
        int n = weights.size();
        int m = mid;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(m >= weights[i]){
                m-=weights[i];
            }
            else {
                cnt++;
                m=mid;
                m-=weights[i];
            }
        }
        cnt+=1;
        if(cnt>days) return false;
        else return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        
        int ans = 0;
        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            if(check(mid, weights, days) == true){
                ans = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return ans;
    }
};


int main() {

    int n;
    cin >> n;

    vector<int> weights(n);

//    cout << "Enter satisfaction values:\n";

    for(int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    int days;
    cin>>days;

    Solution obj;

    int result = obj.shipWithinDays(weights, days);

    cout << result << endl;

    return 0;
}
