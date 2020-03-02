class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> reminder; 
        
        vector<int> res; 
        
        for(int i=0; i<numbers.size(); i++)
        {
            reminder[numbers[i]] = i; 
        }
        
        for(int i=0; i<numbers.size(); i++)
        {
            if (reminder.count(target-numbers[i]) > 0)
            {
                int i2 = reminder[target-numbers[i]];
                // element found
                if (i2 != i)
                {
                    res.push_back(i+1);
                    res.push_back(i2+1);
                    break;
                }
            }
        }
        return res;
    }
};