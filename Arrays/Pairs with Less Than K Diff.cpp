class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int ct = 0, n = arr.size();
        for(int i=0; i<n; i++){
            int idx = lower_bound(arr.begin(), arr.end(), arr[i] + k) - arr.begin();
            idx--;
            ct += max(0, idx - i);
            // cout<<ct<<"\n";
        }
        
        return ct;
    }
};