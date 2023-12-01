
class Solution {
private:
    bool checkvalid(int a[26], int b[26]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        // character count array
        int count1[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            int index = s1[i] - 'a';
            count1[index]++;
        }

        int i = 0;
        // traverse s2 string in a window of size s1 and compare
        int count2[26] = {0};
        int windowSize = s1.length();
        while (i < windowSize && i < s2.length()) {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        if (checkvalid(count1, count2))
            return true;

        // move the window to the next
        while (i < s2.length()) {
            char newchar = s2[i];
            int index = newchar - 'a';
            count2[index]++;

            char oldchar = s2[i - windowSize];
            int oldIndex = oldchar - 'a';
            count2[oldIndex]--;

            i++;

            if (checkvalid(count1, count2))
                return true;
        }

        return false;
    }
};