/*
Link : https://leetcode.com/problems/beautiful-arrangement/description/

*/
class Solution {
public:
    int countArrangement(int n) {
        //bitmask se aise hoga
        //assume ki u have a mask with all bits set to 0 first which refers the whole array
        // if we want to choose one bit first we set that bit to 1 and move ahead again the whole loop runs
        // if bit is 1 means it was set earlier in previous func call, we look for unset bits and set it
        // at end after n times running we reach a point where we selected all and staisfieda all combinations so ans++;

        return help(n,0,0);
    }
    int help(int n,int mask,int i){
        if(n==i)return 1;
        int ans=0;
        for(int j=0;j<n;j++){
            if((mask & (1<<j) )== 0){
                if((i+1)%(j+1)==0 || (j+1)%(i+1)==0){
                    ans += help(n,mask | (1<<j) ,i+1);
                }
            }
        }
        return ans;
    }
};
