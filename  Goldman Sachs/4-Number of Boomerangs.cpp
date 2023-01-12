class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int count =0,n=points.size();
        for(int i =0;i<n;i++){
            unordered_map<int,int> mp;
            for(int j =0;j<n;j++){
                if(i!=j){
                    int x = points[j][0]-points[i][0],y=points[j][1]-points[i][1];
                    int ans = (x*x)+(y*y);
                    mp[ans]++;
                }
            }
            for(auto it : mp){
                if(it.second>1){
                    count+=(it.second)*(it.second-1);
                }
            }
        }
        return count;
    }
};