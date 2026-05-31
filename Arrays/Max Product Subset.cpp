class Solution {
  public:
    int findMaxProduct(vector<int>& arr) {
        // code here
        int M = 1e9+7;
        int n = arr.size();
        if(n == 1) return arr[0];
        int ctn = 0, ct0 = 0;
        int mxn = -2e9;
        
        for(int x : arr){
            if(x == 0){
                ct0++;
            }
            else if(x < 0){
                ctn++;
                mxn = max(mxn, x);
            }
        }
        
        if(ct0 == n || (ctn == 1 && (ctn + ct0) == n)) return 0;
        
        long long ans = 1; 
        bool skipped = false;
        for(int x : arr){
            if(x == 0) continue;
            if((ctn % 2 != 0) && !skipped && x == mxn){
                skipped = true;
                continue;
            }
            ans = (ans * 1ll * abs(x)) % M;
        }
        
        return ans;
    }
};
