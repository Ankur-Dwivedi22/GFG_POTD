class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        int sum = 0, n = arr.size();
        sort(arr.begin(), arr.end());
        int a = -1;
        for(int i=n-1; i>=0; i--){
            if(a == -1){
                a = arr[i];
            }
            else{
                if(a - arr[i] < k){
                    sum += a + arr[i];
                    a = -1;
                }
                else{
                    a = arr[i];
                }
            }
        }
        
        return sum;
    }
};