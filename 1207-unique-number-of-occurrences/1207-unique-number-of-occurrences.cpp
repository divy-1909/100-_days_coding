void countFreq(int arr[], int n, int arr1[]) {
    // Mark all array elements as not visited
    std::vector<bool> visited(n, false);

    // Traverse through array elements and count frequencies
    for (int i = 0; i < n; i++) {
        // Skip this element if already processed
        if (visited[i] == true)
            continue;

        // Count frequency
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        arr1[i] = count;
    }
}

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        int n = arr.size();

        // Assuming input integers are within a specific range
        const int range = 2001; // Adjust based on the range of input integers

        int arr1[range] = {0}; // Array to store frequencies

        countFreq(arr.data(), n, arr1);

        std::unordered_set<int> frequencySet;
        for (int i = 0; i < range; i++) {
            if (arr1[i] > 0) {
                if (!frequencySet.insert(arr1[i]).second) {
                    return false; // Duplicate frequency found
                }
            }
        }

        return true; // All frequencies are unique
    }
};