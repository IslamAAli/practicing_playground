class Solution {
public:
    int charRep1 = -1; 
    int charRep2 = -1;
    
    int strBegin = -1;
    int strEnd = -1;
    
    int lengthOfLongestSubstring(string s) {
        
        if (s.length() == 0)
            return 0;
        
        for(int i=s.length(); i>0 ; i--)
        {
            int s_start = 0;
            int s_len = i;
            
            for (int j=0; j<(s.length()-s_len+1); j++)
            {
                strBegin = j;
                strEnd = j+s_len-1;
                // check for repetitions
                if (!RepetitionExist(s.substr(j,s_len)))
                    return s_len;
            }
        }
        
        return 1; 
    }
    
    bool RepetitionExist(string str)
    {
        //check if repetition is detected before
        if (charRep1 >= strBegin && charRep1 <=strEnd &&
            charRep2 >= strBegin && charRep2 <=strEnd)  
        {
            return true;
        }
        
        bool seen[128] = { false };
        for(int i=0; i< str.length(); i++)
        {
            if(seen[str[i]])
            {
                if (i+strBegin != i+str.find(str[i]))
                {
                    charRep1 = strBegin+str.find(str[i]);
                    charRep2 = i+strBegin; 
                }
                //element found;
                return true;
            }
            else
            {
                seen[str[i]] = true;
            }
        }
        
        return false;
    }
};