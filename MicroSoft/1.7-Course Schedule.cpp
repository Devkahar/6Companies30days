class Solution {
public:
    
    
    bool isCycle(vector<vector<int>>&graph,vector<bool> &visited,vector<bool> &dfsVisited,int start){
        visited[start]=1;
        dfsVisited[start]=1;
        for(int node: graph[start]){
            if(!visited[node]){
                if(isCycle(graph,visited,dfsVisited,node)) return 1;
            }
            else if(dfsVisited[node]) return 1;
        }
        dfsVisited[start]=0;
        return 0;
    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool> visited(n,0),dfsVisited(n,0);
        
        vector<vector<int>> adj(n);
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(isCycle(adj,visited,dfsVisited,i)) return 0;
            }
        }
        
        return 1;
        
    }
};
