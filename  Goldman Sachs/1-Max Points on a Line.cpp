class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0,n= points.size();
        for(int i =0;i<n;i++){
            int samepoint =1;
            double slop;
            unordered_map<double,int> mp;
            for(int j =i+1;j<n;j++){
                if(points[i][0]==points[j][0] && points[i][1]==points[j][1]){
                    samepoint++;
                }else if(points[i][0]==points[j][0]){
                    mp[INT_MAX]++;
                }else{
                    slop = double(points[i][1]-points[j][1])/double(points[i][0]-points[j][0]);
                    mp[slop]++;
                }
            }
            int tans=0;
            for(auto it : mp){
                tans= max(tans,it.second);
            }
            tans+=samepoint;
            ans = max(tans,ans);
        }
        return ans;
    }
};