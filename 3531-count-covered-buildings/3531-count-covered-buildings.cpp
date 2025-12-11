class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int,int>> row; // row[x] = {minY, maxY}
        unordered_map<int, pair<int,int>> col; // col[y] = {minX, maxX}

        // Pre-calc min and max for rows and columns
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            if (!row.count(x)) row[x] = {y, y};
            else {
                row[x].first = min(row[x].first, y);
                row[x].second = max(row[x].second, y);
            }

            if (!col.count(y)) col[y] = {x, x};
            else {
                col[y].first = min(col[y].first, x);
                col[y].second = max(col[y].second, x);
            }
        }

        int covered = 0;

        // Check each building
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            auto &r = row[x];
            auto &c = col[y];

            bool hasLeft  = r.first < y;
            bool hasRight = r.second > y;
            bool hasAbove = c.first < x;
            bool hasBelow = c.second > x;

            if (hasLeft && hasRight && hasAbove && hasBelow)
                covered++;
        }

        return covered;
    }
};
