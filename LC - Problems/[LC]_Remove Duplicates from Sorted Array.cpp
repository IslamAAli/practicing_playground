class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0; 
        while(i < nums.size())
        {
            if (i != nums.size()-1)
            {
                if (nums[i+1] == nums[i])
                {
                    //remove element nums[i+1]
                    nums.erase(nums.begin()+i+1);
                }
                else
                {
                    i ++;
                }
            }
            else
            {
                i++;
            }
        }
        return nums.size();
        
    }
};