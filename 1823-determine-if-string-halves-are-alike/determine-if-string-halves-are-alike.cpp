#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        string a = s.substr(0, n/2);
        string b = s.substr(n/2);

        return countVowels(a) == countVowels(b);
    }

private:
    int countVowels(const string& str) {
        int count = 0;
        for (char ch : str) {
            if (isVowel(ch)) {
                count++;
            }
        }
        return count;
    }

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
};


