class Solution {
    bool DFS(vector<vector<int>>& graph,int node,int time,unordered_map<int,int> &path,vector<bool> &visited){
        path[node]=time;
        visited[node]=1;
        if(node==0){
            return 1;
        }
        for(int it : graph[node]){
            if(!visited[it]){
                if(DFS(graph,it,time+1,path,visited)) return 1;
            }
        }
        path.erase(node);
        return 0;
    }
public:

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size()+1;
        vector<vector<int>> graph(n);
        for(int i =0,u,v,cost;i<n-1;i++){
            u = edges[i][0];
            v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> visited(n);
        unordered_map<int,int> path;
        DFS(graph,bob,0,path,visited);

        queue<vector<int>> q;
        q.push({0,0,0});
        visited.assign(n,0);
        int ans=INT_MIN;
        while(q.size()>0){
            int node = q.front()[0],time = q.front()[1],income = q.front()[2];
            q.pop();
            visited[node]=1;
            if(path.find(node)==path.end()){
                income+=amount[node];
            }else{
                if(time<path[node]){
                    income+=amount[node];
                }else if(time==path[node]){
                    income+=(amount[node]/2);
                }
            }
            
            if(graph[node].size()==1 && node!=0){
                ans = max(ans,income);
            }
            for(auto it: graph[node]){
                if(!visited[it]){
                    q.push({it,time+1,income});
                }
            }
        }

        return ans;
        
    }
};