bool isPossible(vector<int>& bloomDay, int m, int k, int mid) {
    int boucount = 0; // Initialize boucount to 0
    int bounumber = 0;

    for (int i = 0; i < bloomDay.size(); ++i) { // Iterate over all elements in bloomDay
        if (bloomDay[i] <= mid) {
            bounumber++;
            if (bounumber == k) {
                boucount++;
                bounumber = 0;
            }
        } else {
            bounumber = 0;
        }
    }

    return boucount >= m;
}
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        int n = bloomDay.size();

        if (static_cast<long long>(m) * k > n) {
    return ans; // Not enough flowers, impossible to make m bouquets
}


        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
