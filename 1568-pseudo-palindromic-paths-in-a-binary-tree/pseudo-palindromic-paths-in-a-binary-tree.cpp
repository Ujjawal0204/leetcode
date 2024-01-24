/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        if (!root) return 0;

        int count = 0;
        unordered_map<int, int> freq;

        dfs(root, freq, count);

        return count;
    }

private:
    void dfs(TreeNode* node, unordered_map<int, int>& freq, int& count) {
        if (!node) return;

        freq[node->val]++;

        // If it's a leaf node, check if the path is pseudo-palindromic
        if (!node->left && !node->right) {
            if (isPseudoPalindromic(freq)) {
                count++;
            }
        }

        dfs(node->left, freq, count);
        dfs(node->right, freq, count);

        freq[node->val]--;
    }

    bool isPseudoPalindromic(unordered_map<int, int>& freq) {
        int oddCount = 0;

        for (auto& entry : freq) {
            if (entry.second % 2 != 0) {
                oddCount++;
            }
        }

        return oddCount <= 1;
    }
};
