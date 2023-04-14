/* 
Link :
https://leetcode.com/problems/minimum-height-trees/description/

Algorithm : 
-Topological sorting
-Kahn's Algo
-BFS

Approach : 
-Code is similar to Course Schedule ( topological sorting )
-Logic is based on number of edges of a node defines if it is leaf or not so we come from all leaf nodes to the centroid
-even nodes : 2 centroids, odd : 1
-while making adj array count edges in degree array
-Now we know all leafs
-while doing bfs go level wise (level in the sense all leafs at once ) Normal level-order traversal
-Enter centroids value in answer array in the last level of traversal

Bonus :
A graph is a tree with no cycles and the root is the one which is closest to all the nodes (centroid).

*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        vector<int> adj[n];
        vector<int> deg(n,0);
        queue<int> q;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
        }
        for(int i=0;i<n;i++){
            if(deg[i]==1)q.push(i);
        }
        vector<int> ans;
        int vis=0;
        while(!q.empty()){
            int size=q.size();
            ans.clear();
            while(size--){
                int u = q.front();q.pop();
                ans.push_back(u);
                for(auto &v : adj[u]){
                    deg[v]--;
                    if(deg[v]==1){
                        q.push(v);
                    }
                }
            }
        }
        return ans;
    }
};
