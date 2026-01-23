class Solution {
public:
    int minimumPairRemoval(vector<int>& input) {
          int n = input.size();
        if (n <= 1) return 0;

        // Convert to long long to avoid overflow
        vector<long long> nums(n);
        for (int i = 0; i < n; i++) nums[i] = input[i];

        vector<int> prev(n), next(n);
        vector<bool> alive(n, true);

        for (int i = 0; i < n; i++) {
            prev[i] = i - 1;
            next[i] = (i + 1 < n ? i + 1 : -1);
        }

        // Count initial inversions
        int bad = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] > nums[i + 1]) bad++;
        }

        // Min-heap: (sum, index)
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<>
        > pq;

        for (int i = 0; i + 1 < n; i++) {
            pq.push({nums[i] + nums[i + 1], i});
        }

        int ops = 0;

        while (bad > 0) {
            long long sum;
            int i, j;

            // Extract valid minimum-sum adjacent pair
            while (true) {
                auto [s, idx] = pq.top();
                pq.pop();
                i = idx;
                j = next[i];

                if (j != -1 && alive[i] && alive[j]
                    && nums[i] + nums[j] == s) {
                    sum = s;
                    break;
                }
            }

            // Remove old inversion contributions
            if (prev[i] != -1 && nums[prev[i]] > nums[i]) bad--;
            if (nums[i] > nums[j]) bad--;
            if (next[j] != -1 && nums[j] > nums[next[j]]) bad--;

            // Merge
            nums[i] += nums[j];
            alive[j] = false;
            next[i] = next[j];
            if (next[j] != -1) prev[next[j]] = i;

            // Add new inversion contributions
            if (prev[i] != -1 && nums[prev[i]] > nums[i]) bad++;
            if (next[i] != -1 && nums[i] > nums[next[i]]) bad++;

            // Push updated sums
            if (prev[i] != -1)
                pq.push({nums[prev[i]] + nums[i], prev[i]});
            if (next[i] != -1)
                pq.push({nums[i] + nums[next[i]], i});

            ops++;
        }

        return ops;
    }
};
