class Solution {
public:
    int countTriples(int n) {
        int count = 0;

        // Precompute squares
        vector<int> sq(n + 1);
        for (int i = 1; i <= n; i++)
            sq[i] = i * i;

        // Check all a, b, c
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int sum = sq[a] + sq[b];
                // Try finding c such that c^2 == a^2 + b^2
                int c = sqrt(sum);
                if (c <= n && sq[c] == sum)
                    count++;
            }
        }

        return count;
    }
};
