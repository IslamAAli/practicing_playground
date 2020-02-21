class Solution {
public:
    int reverse(int x) {
        string s = std::to_string(x);
        string res = s;
        int itr = 0; 
        
        for(int i=s.length()-1; i>= 0 ; i--)
        {
            res[itr] = s[i];
            itr++;
        }
        
        try
        {
            if (x > 0)
                return stoi(res);
            else
                return -1*stoi(res);
        }
        catch (std::out_of_range)
        {
            return 0;
        }
    }
};