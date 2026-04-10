class Solution {

    int largest(vector<int>& piles) {
        int minE = piles[0];
        for (int i = 1; i < piles.size(); i++) {
            minE = max(minE, piles[i]);
        }
        return minE;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = largest(piles);
        int ans;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            long long hrs = 0;
            for (int i = 0; i < piles.size(); i++) {
                if (piles[i] % mid != 0)
                    hrs++;
                hrs += (piles[i] / mid);
            }
            if (hrs <= h) {
                ans = mid;
                hi = mid - 1;

            } else
                lo = mid + 1;
        }
        return ans;
    }
};
