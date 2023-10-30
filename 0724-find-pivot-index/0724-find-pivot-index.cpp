class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sl=0;
        int sr=0;
        for(int i=0;i<nums.size();i++){
            sr=sr+nums[i];
        }
        int i=0;
        while(i<nums.size()){
            cout<<"i is"<<i<<endl;
            cout<<"left sum is "<<sl<<endl;
            cout<<"right sum is "<<sr<<endl;
            sr=sr-nums[i];
            if(sl==sr){
                return i;
            }
            sl=sl+nums[i];
            
            
            i++;
        }
        // if(sl==sr && sr==0){
        //     return 0;
        // }
        return -1;

    }
};