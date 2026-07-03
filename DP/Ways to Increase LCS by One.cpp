class Solution {
  public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        // code here
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> pos(26);
        
        for(int i=0; i<n2; i++){
            pos[s2[i] - 'a'].push_back(i+1);
        }
        
        vector<vector<int>> lcsl(n1+2, vector<int>(n2+2, 0));
        vector<vector<int>> lcsr(n1+2, vector<int>(n2+2, 0));
        
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(s1[i-1] == s2[j-1]){
                    lcsl[i][j] = 1 + lcsl[i-1][j-1];
                }
                else{
                    lcsl[i][j] = max(lcsl[i-1][j] , lcsl[i][j-1]);
                }
            }
        }
        
        for(int i=n1; i>=0; i--){
            for(int j=n2; j>=0; j--){
                if(s1[i-1] == s2[j-1]){
                    lcsr[i][j] = 1 + lcsr[i+1][j+1];
                }
                else{
                    lcsr[i][j] = max(lcsr[i+1][j], lcsr[i][j+1]);
                }
            }
        }
        
        int lcs = lcsl[n1][n2];
        
        int ways = 0;
        for(int i=0; i<=n1; i++){
            for(char ch='a'; ch<='z'; ch++){
                vector<int> v = pos[ch-'a'];
                for(int p : v){
                    if(lcsl[i][p-1] + lcsr[i+1][p+1] == lcs){
                        ways++;
                        break;
                    }
                }
            }
        }
        
        return ways;
    }
};
