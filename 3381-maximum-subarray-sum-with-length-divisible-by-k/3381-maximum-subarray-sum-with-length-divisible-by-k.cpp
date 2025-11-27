class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> minPref(k, LLONG_MAX);
        
        long long pref = 0;
        long long ans = LLONG_MIN;
        
        minPref[0] = 0;  // prefix sum 0 at index -1
        
        for (int i = 0; i < n; i++) {
            pref += nums[i];
            int mod = (i + 1) % k;

            // Use 128-bit for safe subtraction
            if (minPref[mod] != LLONG_MAX) {
                __int128 diff = (__int128)pref - minPref[mod];
                ans = max(ans, (long long)diff);
            }

            minPref[mod] = min(minPref[mod], pref);
        }
        
        return ans;
    }
};
