#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        // Check if the lengths of the strings are different
        if (s.length() != t.length()) {
            return -1; // Invalid input
        }

        vector<int> frequency(26, 0); // Assuming only lowercase English letters

        // Count the frequency of each character in string s and subtract from the frequency of characters in string t
        for (char ch : s) {
            frequency[ch - 'a']++;
        }

        int steps = 0;

        // Iterate through each character in string t and update the frequency
        for (char ch : t) {
            frequency[ch - 'a']--;

            // If the character is not present in s or its frequency is exhausted, it needs to be replaced
            if (frequency[ch - 'a'] < 0) {
                steps++;
            }
        }

        return steps;
    }
};