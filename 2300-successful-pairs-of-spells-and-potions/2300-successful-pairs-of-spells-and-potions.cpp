class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> an2s;
        for(int i = 0;i<spells.size();i++){
            int s = 0;
            int e = potions.size()-1;
            int ans = -1;
            while(s<=e){
            int mid = s + (e - s)/2;
            long long value = (long)potions[mid]*spells[i] ; 
                if(value >= success){
                    ans = mid;
                    e = mid - 1;
                }
                else s = mid + 1;
            }
            if(ans != -1) {
               an2s.push_back(potions.size()-ans);
            }
            else an2s.push_back(0);
        }
        return an2s;
    }
};
    