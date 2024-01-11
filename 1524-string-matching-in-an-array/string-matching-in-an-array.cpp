class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
      
       //declared a vector named ans of string datatype
       vector<string> ans;

       //now checking each word of the vector words , if it is present in any of other word using .find() function
       for(int i=0;i<words.size();++i){
           for(int j=0;j<words.size();++j){
               //s1.find(s2) returns the index of occurence of string s2 in s1
               // string::npos , a const static value , basically means the end of the string, if it dosen't find the occurence of the string in the given string it returns -1 
               if(i!=j && (words[i].find(words[j]) != string::npos)) {
                   //if words[j] is present in words[i] then push words[j] into ans
                   ans.push_back(words[j]);
               }
           }
       } 

       //since there are possible cases that , one string might occur as a subsquence in more than one string , but we need to return only 1 occurence of such string , so for distinct elements used set<string>

       //declared a set s of string datatype 
       set<string> s;
      
       //traversed the vector ans and inserted the elements into the set s 
       for(int i=0;i<ans.size();++i){
           s.insert(ans[i]);
       }

       //cleared the ans vector 
       ans.clear();

       //iterated the set s and pushed back the elements into a vector ans , as the return type is a vector of datatype string 
       for(auto itr:s){
         ans.push_back(itr);
       }

       return ans;
    }
};