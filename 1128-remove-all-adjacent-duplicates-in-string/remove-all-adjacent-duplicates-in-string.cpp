class Solution {
public:
    string removeDuplicates(string s) {
        int i=0, j=1;
        while ((i<j) && (j<s.size())){
            if(s[i]==s[j]){
                s.erase(i,2);
                i=0;
                j=1;
            }
            else{
                i++;
                j++;
            }
        }
        return s;
    }
};