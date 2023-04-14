/*
Link :
https://leetcode.com/problems/number-of-provinces/description

Algorithm :
-DFS

*/
class Solution {
public:
    void help(vector<int> &vis,int i,vector<vector<int>> &adj){
        vis[i]=1;
        for(auto &x : adj[i]){
            if(vis[x]==0)help(vis,x,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(mat[i][j]==1)adj[i].push_back(j);
            }
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                help(vis,i,adj);
                ans++;
            }
        }
        return ans;
    }
};
