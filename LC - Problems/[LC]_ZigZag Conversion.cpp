class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows == 1)
            return s;
        
        string str = "";
        
        for (int i=0; i <numRows; i++)
        {
            bool end = false;
            if (i < s.length())
                str = str + s[i];
            else
                end = true;
            
            int j=2;
            while (!end)
            {
                int index, index1, index2= 0;
                if (i ==0 || i == numRows-1)
                {
                    index = j*(numRows-1)-i;
                    if (index < s.length())
                    {
                        if (index != i)
                            str = str + s[index];
                    }
                    else
                        end = true;
                }
                else
                {
                    index1 = j*(numRows-1)-i;
                    index2 = j*(numRows-1)+i;
                    
                    if (index1 < s.length() && index1 != i)
                        str = str + s[index1];
                    else
                        end = true;

                    if (index2 < s.length() && index1 != i)
                        str = str + s[index2];
                    else
                        end = true;
                }
                
                j +=2;
            }
        }
        return str;
    }
};