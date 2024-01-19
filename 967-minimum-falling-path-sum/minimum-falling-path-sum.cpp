class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Handle the base case where the matrix has only one row
        if (n == 1) {
            return *min_element(matrix[0].begin(), matrix[0].end());
        }

        // Use a single vector to store the intermediate results for each row
        vector<int> dp(matrix[0].begin(), matrix[0].end());

        // Iterate through the matrix starting from the second row
        for (int i = 1; i < n; ++i) {
            vector<int> newDp(n, 0);

            for (int j = 0; j < n; ++j) {
                int left = (j > 0) ? dp[j - 1] : INT_MAX;
                int up = dp[j];
                int right = (j < n - 1) ? dp[j + 1] : INT_MAX;

                newDp[j] = matrix[i][j] + min({left, up, right});
            }

            dp = move(newDp); // Move the updated vector for the next iteration
        }

        // Find the minimum sum in the last row
        return *min_element(dp.begin(), dp.end());
    }
};