class Solution {
public:
    int strStr(string haystack, string needle) {
        
        size_t found = haystack.find(needle);
        if (found!=std::string::npos)
            return found;
        else
            return -1;
    }
};