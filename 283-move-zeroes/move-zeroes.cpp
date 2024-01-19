class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int x=0;
        while(x <nums.size()){
            int i=0;
            int j=1;
            while(i!=j && j<nums.size()){
                if(nums[i]==0){
                swap(nums[i],nums[j]);
                }
                i++;
                j++;
                }
            x++;
        }
        
    }
};