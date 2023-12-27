class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i,j,k;
        i=0;//for 1
        j=0;
        k=nums.size()-1;
        while(i<=k){
            if(nums[i]==0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[i]==1){
                i++;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[k]);
                k--;
            }
        }
    }
};