// Approach : DP
// TC : O(N)
// SC : O(N)

class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n == 1){
            return 0;
        }
        
        vector<vector<int>> dp(n, vector<int>(2, 0));
        
        for(int i=0; i<n-1; i++){
            dp[i+1][0] = max(dp[i][0], abs(arr[i] - 1) + dp[i][1]);
            dp[i+1][1] = max(dp[i][0] + abs(arr[i+1] - 1) , dp[i][1] + abs(arr[i+1] - arr[i]));
        }
        
        return max(dp[n-1][0] , dp[n-1][1]);
    }
};
