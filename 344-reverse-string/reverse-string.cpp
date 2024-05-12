class Solution {
public:
    void reverseString(vector<char>& s) {
        int a=0;
        int e=s.size();
        while(a<e){
            swap(s[a++],s[--e]);
        }
    }
};