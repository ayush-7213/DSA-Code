class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> rows(numRows);
        int currentRow = 0;
        int direction = -1;  // -1 means up, +1 means down

        for (char c : s) {
            rows[currentRow] += c;

            // Change direction when reaching the top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1)
                direction *= -1;

            currentRow += direction;
        }

        // Combine rows
        string result;
        for (string &row : rows)
            result += row;

        return result;
    }
};
