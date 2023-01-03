class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> mp;
        int n = rectangles.size();
        for(int i =0;i<n;i++){
            mp[{rectangles[i][0],rectangles[i][1]}]++;
            mp[{rectangles[i][2],rectangles[i][3]}]++;
            mp[{rectangles[i][0],rectangles[i][3]}]--;
            mp[{rectangles[i][2],rectangles[i][1]}]--;
        }
        int point = 0;
        for(auto it : mp){
            if(abs(it.second)==1){
                point++;
            }else if(abs(it.second)!=1 && abs(it.second)!=0){
                return 0;
            }
        }
        return point==4;
    }
};
// link: https://leetcode.com/problems/perfect-rectangle/