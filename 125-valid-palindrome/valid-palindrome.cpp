class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j= s.size()-1;

        while(j>=i){
            char ci=tolower(s[i]);
            char cj=tolower(s[j]);

            if (!((ci >= 'a' && ci <= 'z') || (ci >= '0' && ci <= '9'))) {
                i++;
                continue;
            }

            if (!((cj >= 'a' && cj <= 'z') || (cj >= '0' && cj <= '9'))) {
                j--;
                continue;
            }

            if (ci != cj) {
                return false;
            }


            i++;
            j--;

        }
        return true;
    }
};