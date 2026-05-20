class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(n == 0) return false;
        int p = n + 1;
        return (p & (p-1)) == 0;
    }
};