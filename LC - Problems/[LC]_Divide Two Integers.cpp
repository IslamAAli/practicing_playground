class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if (dividend == 0)
            return 0; 
        
        // check the sign of the result 
        bool neg = false;
        
        if (!((dividend >0 && divisor >0) || (dividend <0 && divisor <0)))
            neg = true; 
        
        if (divisor == 1)
        {
            return dividend;
        }
        else if (divisor == -1)
        {
            // check the limit issue 
            if (dividend != INT_MIN)
                return -dividend;
            else
                return INT_MAX;
        }
        else
        {
            // do the division
            int res = 0 ;
            
            unsigned int val, div; 
            
            if (dividend == INT_MIN)
                val = INT_MAX+1;
            else
                val = abs(dividend);
            
            
            if (divisor == INT_MIN)
                div = INT_MAX+1;
            else
                div = abs(divisor);
            
            
            while (val >= div )
            {
                res ++;
                val -= div;
            }
            
            return neg? -res: res ;
        }
        
         
    }
};