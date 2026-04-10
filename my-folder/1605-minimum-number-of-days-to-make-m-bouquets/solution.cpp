class Solution {
    int smallest(vector<int>& bloomDay) {
        int minE = INT_MAX;
        for (auto x : bloomDay) {
            minE = min(minE, x);
        }
        return minE;
    }
    int largest(vector<int>& bloomDay) {
        int maxE = INT_MIN;
        for (auto x : bloomDay) {
            maxE = max(maxE, x);
        }
        return maxE;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size())
            return -1;
        int lo = smallest(bloomDay);
        int hi = largest(bloomDay);
        int ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            long long flrs = 0;
            int count = 0;
            for (int i = 0; i < bloomDay.size(); i++) {
                if (bloomDay[i] <= mid)
                    count++;
                else {
                    flrs += (count / k);
                    count = 0;
                }
            }
            flrs += count/k;

            if (flrs >= m) {
                ans = mid;
                hi = mid - 1;
            } else
                lo = mid + 1;
        }
        return ans;
    }
};
