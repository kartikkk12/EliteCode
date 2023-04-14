/*
Link :
https://leetcode.com/problems/cheapest-flights-within-k-stops/editorial/

Algorithm : 
-BFS
-Dijkstra
-Shortest path ke saare

*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,int>> q;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        q.push({src,0});
        while(!q.empty() && k>=0){
            int size=q.size();
            while(size--){
                auto [u,d] = q.front();q.pop();
                for(auto [v,d2] : adj[u]){
                    if(dist[v] > d + d2){
                        dist[v] = d2 + d;
                        q.push({v,d2+d});
                    }
                }
            }
            k--;
        }
        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};
