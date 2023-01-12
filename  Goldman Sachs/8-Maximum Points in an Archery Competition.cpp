class Solution {
    int mScore =0;
    vector<int> maxScore;
    void solver(vector<int>& aliceArrows,int i,int k,int score,vector<int> &ans){
        if(i==-1 || k==0){ 
            if(score>mScore){
                if(k>0){
                    ans[0]+=k;
                }
                mScore=score;
                maxScore=ans;
            }
            return;
        }

        if(k>aliceArrows[i]){
            ans[i]=aliceArrows[i]+1;
            solver(aliceArrows,i-1,k-aliceArrows[i]-1,score+i,ans);
            ans[i]=0;
        }
        solver(aliceArrows,i-1,k,score,ans);
    }
public:
    vector<int> maximumBobPoints(int k, vector<int>& aliceArrows) {
        int n = aliceArrows.size();
        vector<int> ans(n,0);
        solver(aliceArrows,n-1,k,0,ans);
        return maxScore;
    }
};