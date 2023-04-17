/*
Link :
https://leetcode.com/problems/redundant-connection/description/

Algorithm :
-DSU
-DFS

Approach :
-why we use DSU because when the order of input is important we can use DSU to identify parents of nodes which can help us find cycle in graph
-At the edge where we find parents are same means cycle is found so we can conclude that this is the edge of cycle which will result in cycle
-Same logic can be applied using DFS , we can try to find v as destination from source u in {u,v} edge, if we can reach node v from u means cycle will will be formed if i connect those edge which means this edge is making cycle.
-Note that the adjacency matrix have to be made as we iterate from edge to edge and build one edge after the node finding algo is done.
-See code for understanding
*/


//DSU
class Solution {
public:
    int findp(vector<int> &parent,int i){
        if(parent[i]==i)return i;
        return parent[i] = findp(parent,parent[i]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1);
        for(int i=0;i<=edges.size();i++){
            parent[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int p1=findp(parent,u);
            int p2=findp(parent,v);

            if(p1==p2)return edges[i];
            else {
                parent[p2]=p1;
            }
        }
        return {};
    }
};


//DFS
class Solution {
public:
    vector<int> ans;
    bool dfs(vector<vector<int>> &adj,int u,int v,vector<int> &vis){
       if(u==v)return true;
       if(vis[u]==1)return false;
       vis[u]=1;
       for(auto &x : adj[u]){
           if(dfs(adj,x,v,vis))return true;
       }
       return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        // for(int i=0;i<n;i++){
        //     int u=edges[i][0];
        //     int v=edges[i][1];
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }
        
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            vector<int> vis(n+1,0);
            if(dfs(adj,u,v,vis)){
                ans=edges[i];
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return ans;
    }   
};
