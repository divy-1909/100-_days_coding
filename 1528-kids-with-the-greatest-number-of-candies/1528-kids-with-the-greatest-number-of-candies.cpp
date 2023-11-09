class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& arr, int e) {
        int max = -1;
        std::vector<bool> res;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] + e >= max) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }

        return res;
    }
};
