class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size();
        vector<pair<int,int>> v;
        int p = 0;
        for(int i=0; i<n; i++){
            int diff = a[i] - b[i];
            if(diff > 0){
                p++;
            }
            v.push_back({diff, i});
        }
        
        sort(v.rbegin(), v.rend());
        int ans = 0;
        int k = min(x, max(n-y, p));
        for(int i=0; i<n; i++){
            int ind = v[i].second;
            if(i < k){
                ans += a[ind];
            }
            else{
                ans += b[ind];
            }
        }
        
        return ans;
    }
};