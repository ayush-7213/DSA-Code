class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int res = 0, n = s.size();
        unordered_set<char> set;
        while (r < n) {
            if (set.find(s[r]) != set.end()) {
                set.erase(s[l]);
                l++;
            }
            else{
                set.insert(s[r]);
                res = max(res, r - l + 1);
                r++;
            }
        }
        return res;
    }
};