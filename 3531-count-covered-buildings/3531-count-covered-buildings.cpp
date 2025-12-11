
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> rows, cols;

        // Step 1: Fill row and column maps
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            rows[x].push_back(y);
            cols[y].push_back(x);
        }

        // Step 2: Sort each row and column list
        for (auto& r : rows) sort(r.second.begin(), r.second.end());
        for (auto& c : cols) sort(c.second.begin(), c.second.end());

        int covered = 0;

        // Step 3: Check each building
        for (auto& b : buildings) {
            int x = b[0], y = b[1];

            auto& row = rows[x];
            auto& col = cols[y];

            // Check left and right
            auto it = lower_bound(row.begin(), row.end(), y);
            bool left = (it != row.begin());
            bool right = (next(it) != row.end());

            // Check above and below
            auto it2 = lower_bound(col.begin(), col.end(), x);
            bool above = (it2 != col.begin());
            bool below = (next(it2) != col.end());

            if (left && right && above && below) {
                covered++;
            }
        }

        return covered;
    }
};
