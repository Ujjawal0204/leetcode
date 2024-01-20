class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n, n); // Initialize right with n

        stack<int> s;
        // One pass to find both previous and next smaller elements
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                right[s.top()] = i;
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top(); // Use -1 to indicate no smaller element to the left
            s.push(i);
        }

        // Calculate the final sum
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = (sum + (long long)arr[i] * (i - left[i]) * (right[i] - i)) % MOD;
        }
        
        return sum;
    }
};