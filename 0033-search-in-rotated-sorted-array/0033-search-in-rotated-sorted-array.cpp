#include <iostream>
#include <vector>

class Solution {
private:
    int getpivot(std::vector<int>& nums, int n) {
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;
        while (s < e) {
            if (nums[mid] >= nums[0]) {
                s = mid + 1;
            } else {
                e = mid;
            }
            mid = s + (e - s) / 2;
        }
        return s;
    }

    int binarySearch(std::vector<int>& nums, int s, int e, int target) {
        int start = s;
        int end = e;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (target > nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }

public:
    int search(std::vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = getpivot(nums, n);
        
        // Use binary search on both halves
        int result = binarySearch(nums, 0, pivot - 1, target);
        if (result == -1) {
            result = binarySearch(nums, pivot, n - 1, target);
        }

        return result;
    }
};
