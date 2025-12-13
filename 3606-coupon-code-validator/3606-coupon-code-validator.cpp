class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        
        // Business line priority
        unordered_map<string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
        
        vector<pair<int, string>> validCoupons;
        
        for (int i = 0; i < code.size(); i++) {
            // Check active
            if (!isActive[i]) continue;
            
            // Check business line
            if (order.find(businessLine[i]) == order.end()) continue;
            
            // Check code validity
            if (code[i].empty()) continue;
            
            bool validCode = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    validCode = false;
                    break;
                }
            }
            if (!validCode) continue;
            
            validCoupons.push_back({order[businessLine[i]], code[i]});
        }
        
        // Sort by business line order, then by code
        sort(validCoupons.begin(), validCoupons.end());
        
        vector<string> result;
        for (auto &p : validCoupons) {
            result.push_back(p.second);
        }
        
        return result;
    }
};
