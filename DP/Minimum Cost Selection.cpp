// Approach 1 : Memoisation
// TC : O(N * 4)
// SC : O(N * 4) + Recursive Stack space

class Solution {
  public:
    int n;
    int solve(int ind, int prev, vector<vector<int>> &mat, vector<vector<int>> &dp){
        if(ind == n+1){
            return 0;
        }
        
        if(dp[ind][prev] != -1) return dp[ind][prev];
        
        int c1 = 1e8, c2 = 1e8, c3 = 1e8;
        if(prev != 1){
            c1 = mat[ind-1][0] + solve(ind+1, 1, mat, dp);
        }
        if(prev != 2){
            c2 = mat[ind-1][1] + solve(ind+1, 2, mat, dp);
        }
        if(prev != 3){
            c3 = mat[ind-1][2] + solve(ind+1, 3, mat, dp);
        }
        
        return dp[ind][prev] = min({c1, c2, c3});
    }
    
    int minCost(vector<vector<int>>& mat) {
        // code here
        n = mat.size();
        vector<vector<int>> dp(n+1, vector<int>(4, -1));
        return solve(1, 0, mat, dp);
    }
};

// Approach 2 : Tabulation
// TC : O(N * 4)
// SC : O(N * 4)

class Solution {
  public:
    int n;
    int minCost(vector<vector<int>>& mat) {
        // code here
        n = mat.size();
        vector<vector<int>> dp(n+2, vector<int>(4, 0));
        
        for(int ind=n; ind>=1; ind--){
            for(int prev=3; prev>=0; prev--){
                int c1 = 1e8, c2 = 1e8, c3 = 1e8;
                if(prev != 1){
                    c1 = mat[ind-1][0] + dp[ind+1][1];
                }
                if(prev != 2){
                    c2 = mat[ind-1][1] + dp[ind+1][2];
                }
                if(prev != 3){
                    c3 = mat[ind-1][2] + dp[ind+1][3];
                }
                
                dp[ind][prev] = min({c1, c2, c3});
            }
        }
        
        return dp[1][0];
    }
};

// Approach 3 : Space Optimisation
// TC : O(N * 4)
// SC : O(1)

class Solution {
  public:
    int n;
    int minCost(vector<vector<int>>& mat) {
        // code here
        n = mat.size();
        vector<int> dp(4, 0) , curr(4, 0);
        
        for(int ind=n; ind>=1; ind--){
            for(int prev=3; prev>=0; prev--){
                int c1 = 1e8, c2 = 1e8, c3 = 1e8;
                if(prev != 1){
                    c1 = mat[ind-1][0] + dp[1];
                }
                if(prev != 2){
                    c2 = mat[ind-1][1] + dp[2];
                }
                if(prev != 3){
                    c3 = mat[ind-1][2] + dp[3];
                }
                
                curr[prev] = min({c1, c2, c3});
            }
            dp = curr;
        }
        
        return dp[0];
    }
};
