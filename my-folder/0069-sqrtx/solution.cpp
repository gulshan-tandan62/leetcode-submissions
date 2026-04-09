class Solution {
public:
    int mySqrt(int x) {
        int lo = 0;
        int hi = x;
        int ans;
        while(lo<=hi)
        {
            long long mid = (lo+hi)/2;
            if(mid*mid<=x){ lo = mid+1;ans = mid;}
            else hi = mid-1;

        }
        return ans;
    }
};
