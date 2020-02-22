class Solution {
public:
    bool isPalindrome(int x) {
        
        // negative numbers cannot be palindrome
        if (x <0)
            return false;
        
        int input = x; 
        long rev = 0 ;
        while (input >0 )
        {
            rev = rev*10 + input%10;
            input /= 10;
        }
        
        if (rev == x)
            return true;
        else
            return false;
    }
};