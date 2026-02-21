class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for(auto &ch:paragraph){
            if(ispunct(ch)){
                ch = ' ';
            }
        }
        unordered_map<string,int> mp;
        unordered_set<string> ban(banned.begin(), banned.end());
        stringstream ss(paragraph);
        string word;
        while(ss >> word){
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if(ban.find(word) == ban.end()){
                mp[word]++;
            }
        }
        string ans;
        int max = 0;
        for(auto &val:mp){
            if(val.second > max){
                ans = val.first;
                max = val.second;
            }
        }
        return ans;
    }
};