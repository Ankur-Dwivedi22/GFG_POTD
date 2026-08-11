class Solution {
  public:
    int m, n;
    
    bool isValid(int r, int c, int ct, int k, vector<vector<int>> &sum){
        vector<pair<int,int>> dirs = {{-1,-1}, {-1, +1}, {+1, +1}, {+1, -1}};
        
        for(int i=0; i<4; i++){
            int nr = r + dirs[i].first * ct;
            int nc = c + dirs[i].second * ct;
            if(nr >= 0 && nr < m && nc >= 0 && nc < n) continue;
            return false;
        }
        
        int ans = sum[r + dirs[2].first * ct][c + dirs[2].second * ct];
        
        int ar = r + (dirs[1].first * ct) - 1;
        int ac = c + dirs[1].second * ct;
        
        int br = r + dirs[3].first * ct;
        int bc = c + dirs[3].second * ct - 1;
        
        int cr = r + dirs[0].first * ct - 1;
        int cc = c + dirs[0].second * ct - 1;
        
        if(ar >= 0 && ar < m && ac >= 0 && ac < n){
            ans -= sum[ar][ac];
        }
        
        if(br >= 0 && br < m && bc >= 0 && bc < n){
            ans -= sum[br][bc];
        }
        
        if(cr >= 0 && cr < m && cc >= 0 && cc < n){
            ans += sum[cr][cc];
        }
        
        // cout<<ans<<"\n";
        // return 0;
        
        return ans <= k;
    }
    
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries,
                              int k) {
        // code here
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> sum(m, vector<int>(n, 0));
        sum[0][0] = mat[0][0];
        for(int j=1; j<n; j++){
            sum[0][j] = sum[0][j-1] + mat[0][j];
        }
        
        for(int i=1; i<m; i++){
            sum[i][0] = sum[i-1][0] + mat[i][0];
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                int val = mat[i][j];
                if(i-1 >= 0){
                    val += sum[i-1][j];
                }
                
                if(j-1 >= 0){
                    val += sum[i][j-1];
                }
                
                if(i-1 >= 0 && j-1 >= 0){
                    val -= sum[i-1][j-1];
                }
                
                sum[i][j] = val;
            }
        }
        
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<sum[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        vector<int> ans;
        for(auto q : queries){
            int sr = q[0], sc = q[1];
            // int ct = 0, mxLen = 0;
            // while(isValid(sr, sc, ct, k, sum)){
            //     mxLen = max(mxLen, 2*ct+1);
            //     ct++;
            // }
            
            int lo = 0, hi = min(m, n), mxLen = 0;
            while(lo <= hi){
                int ct = lo + (hi - lo) / 2;
                if(isValid(sr, sc, ct, k, sum)){
                    mxLen = max(mxLen, 2*ct+1);
                    lo = ct + 1;
                }
                else{
                    hi = ct - 1;
                }
            }
            
            if(mxLen == 0) mxLen = -1;
            if(mxLen == 1){
                if(mat[sr][sc] > k) mxLen = -1;
            }
            ans.push_back(mxLen);
        }
        
        return ans;
    }
};