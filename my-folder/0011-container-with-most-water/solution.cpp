class Solution {
public:
    int maxArea(vector<int>& height) {
        int mWater = 0;
        int l=0;
        int r=height.size()-1;
        while(l<r)
        {
            int ht = min(height[l],height[r]);
            int wd = (r-l);
            mWater = max(mWater,ht*wd);
            if(height[l]<height[r])l++;
            else r--;
        }
        return mWater;
    }
};
