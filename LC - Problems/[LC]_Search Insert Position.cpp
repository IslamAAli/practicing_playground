class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int>::iterator itr = find (nums.begin(), nums.end(), target);
        
        if (itr != nums.end())
        {
            // element found
            return distance(nums.begin(), itr);
        }
        else
        {
            // element not found;
            for (int i=0; i<nums.size(); i++)
            {
                if (target <= nums[i])
                {
                    return i;
                }
            }
        }
        
        return nums.size();
    }
};