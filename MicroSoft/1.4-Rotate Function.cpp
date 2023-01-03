class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0,org=0,n=nums.size();
        for(int i =0;i<n;i++){
            sum+=nums[i];
            org+= i*nums[i];
        }
        int mx= INT_MIN;
        for(int i =n-1;i>=0;i--){
            org+= sum- (nums[i]*n);
            mx=max(mx,org);
        }
        return mx;
    }
};