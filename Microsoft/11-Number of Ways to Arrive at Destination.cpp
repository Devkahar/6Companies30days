
class Solution {
    int MOD = 1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>> graph(n);
        for(int i=0,u,v,c;i<roads.size();i++){
            u = roads[i][0],v=roads[i][1],c=roads[i][2];
            graph[v].push_back({u,c});
            graph[u].push_back({v,c});
        }
        vector<long long> ways(n,0),dist(n,LONG_MAX);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [d,node] = pq.top();
            pq.pop();
            if(d>dist[node]) continue;
            for(auto [it,cost]:graph[node]){
                if(dist[it]>d+cost){
                    dist[it]=d+cost;
                    pq.push({dist[it],it});
                    ways[it]=ways[node];
                }else if(d+cost==dist[it]){
                    ways[it]=(ways[it]+ways[node])%MOD;
                }
            }
        }

        return ways[n-1];
    }
};