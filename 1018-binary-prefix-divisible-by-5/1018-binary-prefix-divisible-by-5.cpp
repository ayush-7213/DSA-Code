class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int prefix=0;

        for(int bit : nums){
            prefix=(prefix * 2 + bit) %5;
            ans.push_back(prefix==0);
        }
        return ans;
    }
};