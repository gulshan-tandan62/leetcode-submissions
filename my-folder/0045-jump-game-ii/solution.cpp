class Solution {
public:
    int jump(vector<int>& nums) {
        int maxJump = 0;
        int n = nums.size();
        int jump = 0;
        int currJump = 0;
        for(int i=0;i<n-1;i++)
        {
            maxJump = max(maxJump,i+nums[i]);
            if(currJump == i) {
                jump++;
                currJump = maxJump;
            }
        }
        return jump;
    }
};
