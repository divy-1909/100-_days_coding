class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int k) {
        long long n = nums.size();
        long long maxi = *std::max_element(nums.begin(), nums.end());
        long long i = 0, j = 0, cnt = 0, ans = 0;

        for (j = 0; j < n; j++) {
            if (nums[j] == maxi) {
                cnt++;
            }
            if (cnt >= k) {
                for (; cnt >= k; i++) {
                    ans += n - j;
                    if (nums[i] == maxi) {
                        cnt--;
                    }
                }
            }
        }
        return ans;
    }
};
