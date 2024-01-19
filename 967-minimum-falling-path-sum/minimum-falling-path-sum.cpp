class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Handle the base case where the matrix has only one row
        if (n == 1) {
            return *min_element(matrix[0].begin(), matrix[0].end());
        }

        // Iterate through the matrix starting from the second row
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int left = (j > 0) ? matrix[i - 1][j - 1] : INT_MAX;
                int up = matrix[i - 1][j];
                int right = (j < n - 1) ? matrix[i - 1][j + 1] : INT_MAX;

                matrix[i][j] += min({left, up, right});
            }
        }

        // Find the minimum sum in the last row
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};
