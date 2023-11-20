class Solution {
public:
    int maxArea(vector<int>& height) {
         int n = height.size();
        int left=0;
        int right=n-1;
        int area=0;
        while(left<=right){
            int mini = min(height[left],height[right]);
            int  w=right-left;
            area=max(area,w*mini);
            if(height[right]>height[left]){
                left++;
            }
            else right--;
        }
        return area;
    }
};