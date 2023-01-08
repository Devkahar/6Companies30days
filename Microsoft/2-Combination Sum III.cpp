class Solution {
    void DFS(int k,int n,int start,vector<int> &ans,vector<vector<int>> &res){
        if(k==0 && n==0){
            res.push_back(ans);
            return;
        };
        if(k==0 || start>9) return;
        if(start<=9){
            ans.push_back(start);
            DFS(k-1,n-start,start+1,ans,res);
        }
        ans.pop_back();
        DFS(k,n,start+1,ans,res);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans;
        vector<vector<int>> res;
        if(n>45) return res;
        DFS(k,n,1,ans,res);
        return res;
    }
};
// link: https://leetcode.com/problems/combination-sum-iii/description/