class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> temp;
        for(int i=0; i<nums.size(); i++){
            if(i == 0 || nums[i] != nums[i - 1]){
                temp.push_back(nums[i]);
            }
        }
        nums = temp;
        return temp.size();
    }
};