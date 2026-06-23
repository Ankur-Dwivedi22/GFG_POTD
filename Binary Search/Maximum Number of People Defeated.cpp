class Solution {
  public:
    bool check(int n, int p){
        long long sum = n * 1ll * (n + 1) * (2*n + 1) / 6;
        return (sum <= p);
    }
    
    int maxPeopleDefeated(int p) {
        // Code Here
        int lo = 1, hi = 1e4;
        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(check(mid, p)){
                lo = mid + 1;
                ans = mid;
            }
            else{
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};
