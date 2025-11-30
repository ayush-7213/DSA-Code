class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;

        int need = total % p;
        if (need == 0) return 0;     // Already divisible

        unordered_map<int, int> lastIndex;
        lastIndex.reserve(nums.size());
        lastIndex[0] = -1;           // Prefix before array

        long long prefix = 0;
        int minLen = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;

            int target = (prefix - need + p) % p;

            if (lastIndex.count(target)) {
                minLen = min(minLen, i - lastIndex[target]);
            }

            lastIndex[prefix] = i;  // Update latest index
        }

        return (minLen == nums.size()) ? -1 : minLen;
    }
};
