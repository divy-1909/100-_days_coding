class Solution {
public:
    int reverse(int x) {
        int ans=0;
        for(;x!=0;x=x/10){
            int digit=x%10;
            if ((ans>INT_MAX/10)||(ans<INT_MIN/10)){
                return 0;
            }
            ans=(ans*10)+digit;

        }
        return ans;    
    } 

};  