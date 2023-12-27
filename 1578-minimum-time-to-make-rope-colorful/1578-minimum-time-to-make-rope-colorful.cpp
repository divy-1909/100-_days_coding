class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res=0, cost=0,sum=0;
        int n=neededTime.size();
        for(int i=0;i<n;i++){
            if(i>0 && colors[i]!=colors[i-1]){
                res+=sum-cost;
                sum=cost=0;
            }
            sum+=neededTime[i];
            cost=max(cost,neededTime[i]);
        }
        res+=sum-cost;
        return res;
    }
};