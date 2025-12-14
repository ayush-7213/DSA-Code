class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> result;
        int row = 0, col = 0;
        int dir = 1; // 1 = up-right, -1 = down-left

        for (int i = 0; i < m * n; i++) {
            result.push_back(mat[row][col]);

            if (dir == 1) { // moving up-right
                if (col == n - 1) {
                    row++;
                    dir = -1;
                } else if (row == 0) {
                    col++;
                    dir = -1;
                } else {
                    row--;
                    col++;
                }
            } else { // moving down-left
                if (row == m - 1) {
                    col++;
                    dir = 1;
                } else if (col == 0) {
                    row++;
                    dir = 1;
                } else {
                    row++;
                    col--;
                }
            }
        }

        return result;
    }
};
