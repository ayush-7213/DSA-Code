class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int mx = 0, st = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (last[s[i]] >= st)
                st = last[s[i]] + 1;
            last[s[i]] = i;
            mx = max(mx, i - st + 1);
        }
        return mx;
    }
};