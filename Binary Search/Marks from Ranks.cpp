// Approach : Prefix Sum + Binary Search 
// TC : O(N + Q * logN)
// SC : O(N)
class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        int n = l.size();
        vector<int> pre(n);
        pre[0] = r[0] - l[0] + 1;
        for(int i=1; i<n; i++){
            int sz = r[i] - l[i] + 1;
            pre[i] = pre[i-1] + sz;
        }
        
        vector<int> ans;
        for(int rk : rank){
            int ind = lower_bound(pre.begin(), pre.end(), rk) - pre.begin();
            if(ind-1 >= 0){
                rk -= pre[ind-1];
            }
            int v = l[ind] + rk - 1;
            ans.push_back(v);
        }
        
        return ans;
    }
};
