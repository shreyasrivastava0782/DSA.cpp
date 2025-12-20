class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int count = 0;

        // Traverse each column
        for (int col = 0; col < m; col++) {
            // Check rows in this column
            for (int row = 1; row < n; row++) {
                if (strs[row][col] < strs[row - 1][col]) {
                    count++;     // delete this column
                    break;       // move to next column
                }
            }
        }
        return count;
    }
};
