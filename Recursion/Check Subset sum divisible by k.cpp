class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        if (n >= k) return true;
        vector<vector<int>> ahead(k, vector<int>(2, 0)) , curr(k, vector<int>(2, 0));
        ahead[0][1] = curr[0][1] = 1;
        
        for(int ind=n-1; ind>=0; ind--){
            for(int rem=k-1; rem>=0; rem--){
                for(int taken=1; taken>=0; taken--){
                        int new_rem = (rem + arr[ind]) % k;
                        bool take = ahead[new_rem][1];
                        bool notTake = ahead[rem][taken];
                        
                        curr[rem][taken] = (take || notTake);
                }
            }
            ahead = curr;
        }
        return ahead[0][0];
    }
};