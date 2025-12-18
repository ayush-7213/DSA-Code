class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> profit(n + 1, 0);     // prefix sum of strategy[i] * prices[i]
        vector<long long> priceSum(n + 1, 0);   // prefix sum of prices[i]

        // Build prefix sums
        for (int i = 0; i < n; ++i) {
            profit[i + 1] = profit[i] + (long long)strategy[i] * prices[i];
            priceSum[i + 1] = priceSum[i] + prices[i];
        }

        long long maxGain = 0;

        // Try all windows of size k
        for (int i = 0; i <= n - k; ++i) {
            int mid = i + k / 2;
            int end = i + k;

            // Original profit in window [i, end)
            long long original = profit[end] - profit[i];

            // Modified profit: first half → 0, second half → sell
            long long modified = priceSum[end] - priceSum[mid];

            long long gain = modified - original;
            maxGain = max(maxGain, gain);
        }

        return profit[n] + maxGain;
    }
};