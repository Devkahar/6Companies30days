class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int i =0,j = n-1;
        while(i+1<n && nums[i]<=nums[i+1]){
            i++;
        }

        while(j-1>=0 && nums[j-1]<=nums[j]){
            j--;
        }
        if(i==n-1) return 0;
        int mn = INT_MAX,mx=INT_MIN;
        for(int k=i;k<=j;k++){
            mn = min(mn,nums[k]);
            mx = max(mx,nums[k]);
        }

        while(i-1>=0 && nums[i-1]> mn)i--;
        while(j+1<n && nums[j+1]<mx) j++;
        
        return j-i+1;
    }
};