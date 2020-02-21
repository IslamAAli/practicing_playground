class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        
        int res = 0; 
        if (s.length() <= 1)
            return s.length();
        
        int map[256] = {0};
        
        for(int i=0, j=0; j<s.length(); j++)
        {
            map[s[j]] ++ ;
            while (map[s[j]] > 1)
            {
                map[s[i]] --;
                i++; 
            }
            res = max(res, j-i+1);
        }
        
        return res;
    }
};