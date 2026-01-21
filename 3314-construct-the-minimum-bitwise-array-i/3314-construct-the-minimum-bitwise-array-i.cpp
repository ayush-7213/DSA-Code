class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int p : nums) {
            if (p == 2) {
                ans.push_back(-1);
                continue;
            }

            int t = 0;
            int temp = p;
            while (temp & 1) {
                t++;
                temp >>= 1;
            }

            ans.push_back(p - (1 << (t - 1)));
        }

        return ans;
    }
};
