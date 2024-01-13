#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        // Check if the lengths of the strings are different
        if (s.length() != t.length()) {
            return -1; // Invalid input
        }

        unordered_map<char, int> frequency;

        // Count the frequency of each character in string s
        for (char ch : s) {
            frequency[ch]++;
        }

        int steps = 0;

        // Iterate through each character in string t and update the frequency
        for (char ch : t) {
            if (frequency.find(ch) != frequency.end() && frequency[ch] > 0) {
                frequency[ch]--;
            } else {
                // If the character is not present in s or its frequency is exhausted, it needs to be replaced
                steps++;
            }
        }

        return steps;
    }
};