class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1, sufix=1, ans=INT_MIN, n=nums.size();

        for(int i=0; i<=n-1; i++){
            if(prefix==0) prefix=1;
            if(sufix==0) sufix=1;

            prefix *= nums[i];
            sufix *= nums[n-i-1]; 
            ans = max(ans, max(prefix,sufix));
        }
        return ans;
    }
};