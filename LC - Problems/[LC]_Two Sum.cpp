class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        
        for (int i=0; i<nums.size(); i++)
        {
            int reminder = target - nums[i];
            // search for i inside the vector
            
            vector<int>::iterator it = find(nums.begin()+i+1, nums.end(), reminder);
            if (it != nums.end())
            {
                // element found
                int index = distance(nums.begin(), it);
                res.push_back(i);
                res.push_back(index);
                break;
            }
        }
        
        return res;
        
    }
};