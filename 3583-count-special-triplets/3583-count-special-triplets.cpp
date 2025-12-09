class Solution {
public:
    static const int MOD = 1000000007;

    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        const int MAXV = 200000; // nums[i] up to 1e5, target = nums[j]*2 <= 2e5

        vector<int> leftCount(MAXV + 1, 0);
        vector<int> rightCount(MAXV + 1, 0);

        for (int x : nums) rightCount[x]++;

        int ans = 0;
        for (int j = 0; j < n; ++j) {
            int val = nums[j];
            rightCount[val]--;           // j no longer in right
            int target = val * 2;

            if (target <= MAXV) {
                // do multiplication in 64-bit only inside the expression to avoid overflow
                int add = (int)(((int64_t)leftCount[target] * rightCount[target]) % MOD);
                ans = (ans + add) % MOD;
            }

            leftCount[val]++;            // j becomes part of left
        }

        return ans;
    }
};
