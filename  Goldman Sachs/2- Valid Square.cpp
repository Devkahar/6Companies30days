class Solution {
public:
    double dist(vector<int>& p1, vector<int>& p2){
        return sqrt(pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        vector<vector<int>> vi = {p1,p2,p3,p4};
        set<double> st; 
        for(int i =0;i<4;i++){
            for(int j =i+1;j<4;j++){
                double d = dist(vi[i],vi[j]);
                if(d==0) return 0;
                st.insert(d);
            }
        }
        return st.size()==2;
    }
};