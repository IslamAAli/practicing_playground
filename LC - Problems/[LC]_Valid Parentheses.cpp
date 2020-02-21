class Solution {
public:
    bool isValid(string s) {
        stack<char> pars; 
        map<char, char> mates;
        mates[')'] = '(';
        mates['}'] = '{';
        mates[']'] = '[';
        
        for (int i=0; i <s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                pars.push(s[i]);
            }
            else
            {
                if (pars.empty())
                    return false;
                else
                {
                    if (pars.top() == mates[s[i]])
                        pars.pop();
                    else
                        return false;
                }
                
            }
        }
        
        if (pars.empty())
            return true;
        else
            return false;
    }
};