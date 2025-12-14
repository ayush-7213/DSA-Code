class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        vector<int> seats;
        
        // Collect seat positions
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                seats.push_back(i);
            }
        }
        
        int totalSeats = seats.size();
        // Invalid cases
        if (totalSeats == 0 || totalSeats % 2 != 0) {
            return 0;
        }
        
        long long result = 1;
        int sections = totalSeats / 2;
        
        // Count choices between consecutive sections
        for (int i = 0; i < sections - 1; i++) {
            int rightSeat = seats[2 * i + 1];
            int leftSeat = seats[2 * i + 2];
            result = (result * (leftSeat - rightSeat)) % MOD;
        }
        
        return result;
    }
};
