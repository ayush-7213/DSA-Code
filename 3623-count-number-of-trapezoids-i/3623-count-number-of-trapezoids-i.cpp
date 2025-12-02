class Solution {
public:
    static const long long MOD = 1'000'000'007;

    long long nC2(long long n) {
        if (n < 2) return 0;
        return (n * (n - 1) / 2) % MOD;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> freq;

        // Count points by y-coordinate
        for (auto &p : points)
            freq[p[1]]++;

        long long sumC = 0, sumC2 = 0;

        // Compute sum(c_i) and sum(c_i^2)
        for (auto &e : freq) {
            long long c = nC2(e.second);
            sumC = (sumC + c) % MOD;
            sumC2 = (sumC2 + (c * c) % MOD) % MOD;
        }

        // result = (sumC^2 - sumC2) / 2 mod M
        long long ans = ( (sumC * sumC) % MOD - sumC2 + MOD ) % MOD;

        // divide by 2 using modular inverse (inv(2) mod M = (MOD+1)/2)
        long long inv2 = (MOD + 1) / 2;

        ans = (ans * inv2) % MOD;

        return (int)ans;
    }
};
