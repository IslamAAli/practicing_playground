class Solution {
public:
    int romanToInt(string s) {
        
        map<char, int> romanCorresp;
        romanCorresp['I'] = 1;
        romanCorresp['V'] = 5;
        romanCorresp['X'] = 10;
        romanCorresp['L'] = 50;
        romanCorresp['C'] = 100;
        romanCorresp['D'] = 500;
        romanCorresp['M'] = 1000;
        
        int sum = 0 ;
        for(int i=0; i<s.length(); i++)
        {
            if (i<s.length()-1 && (
                (s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')) ||
                (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) ||
                (s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')) 
                ))
            {
                sum -= romanCorresp[s[i]];
            }
            else
            {
                sum += romanCorresp[s[i]];
            }
        }
        
        return sum; 
    }
};