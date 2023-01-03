class Solution {
    
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n);
        int mxSize=0,mxSizeIdx=-1;
        for(int i =n-1;i>=0;i--){
            dp[i].push_back(nums[i]);
            int mxIdx=-1,mx=0;
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0){
                    if(dp[j].size()>mx){
                        mxIdx=j;
                        mx=dp[j].size();
                    }
                }
            }
            if(mxIdx!=-1){
                dp[i].insert(dp[i].end(),dp[mxIdx].begin(),dp[mxIdx].end());
            }
            if(dp[i].size()>mxSize){
                mxSize=dp[i].size();
                mxSizeIdx=i;
            }
        }
        return dp[mxSizeIdx];
    }
};