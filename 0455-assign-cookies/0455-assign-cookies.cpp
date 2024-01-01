class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;
        int count = 0;

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                count++;
                i++;
            }
            j++;
        }

        return count;
    }
};
//This modification ensures that the j index is always incremented, and the i index is only incremented when a suitable cookie is found for a child
