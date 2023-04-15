/*
Link :
https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/

Algorithm :
-DP

Approach :
-Normal select / Not select approach but optimised! , how? 
-Selecting K coins from top means you can still select elements from single pile k times
-So once i select some element from one pile i dont need to come back and select from the same pile again, why?
-because that i will be doing in that recursive call in a for loop and also not needed see this example :-

3  
10  7  18
11  5  4

-If i select 3 first and move to next call then select 18 and then move to next call and select 10 : sum is 31 and selected items are also same
-And if i select 3 and then explore all other options then in the same func call because of loop i select 3 and 10 and then go to next call and select 18 : sum is 31 and items selected are also same
-But notice ki in the first method we still have to loop through all the elements again and select not select randomly, but in the second method we dont need to come back to same pile again
-This saves a lot of time and is high level Select/ Not select when we are dealing with not a single array but multiple arrays and condition is kind of like this that we never have to visit again in the same array
-Even if it is not like that try to make it that way that once working on one array complete the job of that array in that func call , otherwise no matter what dp u use it will give TLE.
*/

class Solution {
public:
    int dp[1001][2001];
    int help(vector<vector<int>>& piles,int k,int ind){
        if(ind==piles.size())return 0;
        if(dp[ind][k]!=-1)return dp[ind][k];
        int maxans=0;
        int sum=0;
        maxans=max(maxans,help(piles,k,ind+1));
        for(int i=0;i<min(k,(int)piles[ind].size());i++){
            sum+=piles[ind][i];
            maxans=max(sum+help(piles,k-i-1,ind+1),maxans);
        }
        return dp[ind][k] = maxans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return help(piles,k,0);
    }
};
