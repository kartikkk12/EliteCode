/*
Link :
https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/

Algorithm : 
-DP
-Frequency memoize per index

Approach :
-Frequency of 26 chars at a perticualr index in all strings of the array can be used for precomputation
-freq[words[0].size()][26];
-Because we get same ans from 2 multiple strings and then can add them to find the last ans.
-Example :-
    - abcd bdae abab , target=aba
    - here if we select [0][0] then call recursive for f(1,1) {where first para denotes index in string, second denote index in target}
    - then out search space is reduced to i+1 - length(string) which is same as selecting [2][0] and then calling ans , we just need to add both the ans( but we didnt needed to calulate for 2nd one as we knew it would also give same ans as [0][0])
    - this is where we were doing a lot of work so we can store all character frequency and per index shown below
*/

//Approach 1st half cases passsed
class Solution {
public:
    int dp[1001][1001];
    int x=1e9 +7;
    int numWays(vector<string>& words, string target) {
        memset(dp,-1,sizeof(dp));
        return help(words,target,0,0);
    }
    int help(vector<string>& words,string target,int ix,int jx){
        if(jx==target.size())return 1;
        if(words[0].size()==ix)return 0;
        if(dp[ix][jx]!=-1)return dp[ix][jx];
        int cnt=0;
        for(int i=0;i<words.size();i++){
            for(int j=ix;j<words[i].size();j++){
                if(target[jx]==words[i][j]){
                    cnt=(cnt+ help(words,target,j+1,jx+1))%x;
                }
            }
        }
        return dp[ix][jx]=cnt % x;
    }
};

//Thought map would work but knew its gonna effect time complexity, just skip some iterations
class Solution {
public:
    int dp[1001][1001];
    int x=1e9 +7;
    int numWays(vector<string>& words, string target) {
        memset(dp,-1,sizeof(dp));
        unordered_map<string,vector<vector<int>>> m;
        for(int i=0;i<words.size();i++){
            vector<vector<int>> v(26);
            for(int j=0;j<words[0].size();j++){
                v[words[i][j]-'a'].push_back(j);
            }
            m[words[i]] = v;
        }
        return help(words,target,0,0,m);
    }
    int help(vector<string>& words,string &target,int ix,int jx,unordered_map<string,vector<vector<int>>> &m){
        if(jx==target.size())return 1;
        if(words[0].size()==ix)return 0;
        if(dp[ix][jx]!=-1)return dp[ix][jx];
        int cnt=0;
        for(int i=0;i<words.size();i++){
            for(auto &j : m[words[i]][target[jx]-'a']){
                if((words[0].size()-j-1) < (target.size()-jx-1))break;
                if(j>=ix)
                cnt = (cnt + help(words,target,j+1,jx+1,m) ) %x ;
            }
        }
        return dp[ix][jx]=cnt % x;
    }
};

//Final approach
// state is : per index i(in words[0]) how many alphabets same as target[j] are present
// this state is efficient
// i thought of only per one string at that index is the target[j] == string[i]
// but this precomputes all char x occuring at index i for all the strings in array.
class Solution {
public:
    int dp[1001][1001];
    long long x=1e9 +7;
    int numWays(vector<string>& words, string target) {
        memset(dp,-1,sizeof(dp));
        int n=words.size(),m=target.size();
        vector<vector<int>> v (words[0].size(),vector<int>(26));
        for(int i=0;i<n;i++){
            for(int j=0;j<words[0].size();j++){
                v[j][words[i][j]-'a']++;
            }
        }
        return help(target,0,0,v);
    }
    int help(string &target,int ix,int jx,vector<vector<int>> &v){
        if(jx==target.size())return 1;
        if(v.size()==ix)return 0;
        if(dp[ix][jx]!=-1)return dp[ix][jx];
        int cnt=0;
        int a = help(target,ix+1,jx,v);
        long long  b = ((help(target,ix+1,jx+1,v) % x) * (v[ix][target[jx]-'a']) % x) % x;

        cnt = (a + b) % (int)x;
      
        return dp[ix][jx]=cnt % (int)x;
    }
};
