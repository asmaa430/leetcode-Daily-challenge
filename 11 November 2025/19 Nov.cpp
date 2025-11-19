class Solution {
public:
    int findFinalValue(vector<int>& nums, int n) {
     unordered_set<int> numSet(nums.begin(), nums.end());
        while (numSet.count(n)) {
            n *= 2; }
        
        return n; }
};