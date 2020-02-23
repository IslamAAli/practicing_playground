class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int max = 0 ;
        for (int i=0; i<height.size(); i++)
        {
            for(int j=i+1; j<height.size(); j++)
            {
                int tmp_area = (j-i) * min(height[i],height[j]);
                if (tmp_area > max )
                    max = tmp_area;
            }
        }
        return max;
    }
};