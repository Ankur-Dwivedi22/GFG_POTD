class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // code here.
        sort(arr.begin(), arr.end());
        int ans = 1;
        for(int a : arr){
            if(a <= ans){
                ans += a;
            }
            else break;
        }
        
        return ans;
    }
};