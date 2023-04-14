/*
Links :
https://leetcode.com/problems/all-paths-from-source-to-target/description/

Algorithm :
-DFS
-Explore all possibility

*/

class Solution {
public:
    void help(int i,vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int> temp){
        if(i==graph.size()-1){
            temp.push_back(i);
            ans.push_back(temp);
            return;
        }
        temp.push_back(i);
        for(auto &x : graph[i]){
            help(x,graph,ans,temp);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        help(0,graph,ans,{});
        return ans;
    }
};
