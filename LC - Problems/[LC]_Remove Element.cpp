class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int sizeL = nums.size();
        int itr = 0 ;
        for(int i=0; i<sizeL; i++)
        {
            if (nums[itr] == val)
            {
                nums.erase(nums.begin()+itr);
            }
            else
            {
                itr ++ ;
            }
        }
        return nums.size();
    }
};