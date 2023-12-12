class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> num3(m + n, 0); // Initialize num3 with size m + n
        int i = 0, j = 0, k = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                num3[k++] = nums1[i++];
            } else {
                num3[k++] = nums2[j++];
            }
        }

        while (i < m) {
            num3[k++] = nums1[i++];
        }

        while (j < n) {
            num3[k++] = nums2[j++];
        }

        // Copy the merged array back to nums1
        for (int x = 0; x < m + n; x++) {
            nums1[x] = num3[x];
        }
    }
};
