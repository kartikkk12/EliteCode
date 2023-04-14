/*
Link :
https://leetcode.com/problems/network-delay-time/description/

Algorithm :
-Shortest path
-BFS

*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //1-based indexing care
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        queue<pair<int,int>> q;
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        q.push({k,0});
        while(!q.empty()){
            auto [u,t] = q.front();q.pop();
            for(auto [v,t2] : adj[u]){
                if(dist[v] > t + t2 ){
                    dist[v] = t + t2;
                    q.push({v,dist[v]});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            //means this node never visited
            if(dist[i]==INT_MAX)return -1;
            ans=max(dist[i],ans);
        }
        return ans;

    }
};
