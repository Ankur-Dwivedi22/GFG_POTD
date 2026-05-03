// Approach : Stable sort
// TC : O(N * logN)
// SC : O(N) since stable sort(like merge sort) it needs buffer
class Solution {
  public:
    static bool cmp(int a, int b){
        int bit_ct_a = __builtin_popcount(a);
        int bit_ct_b = __builtin_popcount(b);

        return bit_ct_a > bit_ct_b;
    }
    
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        stable_sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};

// Approach 2 : Brute Force using maps
// TC : O(N * log33) => O(N) since number of keys , k = 0,1,..32
// SC : O(N)
class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        int n = arr.size();
        map<int, vector<int>> mp;
        
        for(int i=0; i<n; i++){
            int num = arr[i];
            int setbits = 0;
            for(int j=31; j>=0; j--){
                int bit = (num >> j) & 1;
                if(bit == 1) setbits++;
            }
            mp[setbits].push_back(num);
        }
        
        vector<int> ans;
        for(auto it=mp.rbegin(); it!=mp.rend(); it++){
            vector<int> v = it->second;
            for(int val : v){
                ans.push_back(val);
            }
        }
        
        return ans;
    }
};