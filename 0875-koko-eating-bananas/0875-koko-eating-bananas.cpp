class Solution {
public:
    long long totalhours(vector<int>& piles, int hourly) {
        long long totalh = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++) {
            totalh += (piles[i] + hourly - 1) / hourly;  // No need for ceil here
        }
        return totalh;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        sort(piles.begin(), piles.end());

        int e = piles.back();  // Using the largest element as the upper bound
        int ans = -1;

        while(s <= e) {
            int mid = s + (e - s) / 2;
            long long totalh = totalhours(piles, mid);  // Change the type to long long

            if(totalh <= h) {
                e = mid - 1;
                ans = mid;  // Update the answer when a valid speed is found
            }
            else {
                s = mid + 1;
            }
        }

        return ans;
    }
};
