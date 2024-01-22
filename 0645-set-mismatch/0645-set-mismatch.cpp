
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                ans.push_back(nums[i]);
            }
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (find(nums.begin(), nums.end(), i) == nums.end()) {
                ans.push_back(i);
                break;
            }
        }

        return ans;
    }
};
