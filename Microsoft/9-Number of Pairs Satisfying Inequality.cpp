class Solution {
    long long ans=0;
    int diff;
    long long merge(vector<int>& nums,int l,int r){
        if(l==r) return 0;
        int mid = (l+r)/2;
        int l1= l,r1= mid,l2=mid+1,r2 =r;
        long long res = merge(nums,l1,r1)+merge(nums,l2,r2);
        vector<int> arr;
        for(int j=l2;j<=r2;j++){
            int idx =upper_bound(nums.begin()+l1,nums.begin()+r1+1,(nums[j]+diff))-nums.begin()-1;
            if(idx<=r1){
                res+=(idx-l1+1);
            }
        }
        while(l1<=r1 && l2<=r2){
            if(nums[l1]<nums[l2]) arr.push_back(nums[l1++]);
            else arr.push_back(nums[l2++]);
        }
        while(l1<=r1) arr.push_back(nums[l1++]);
        while(l2<=r2) arr.push_back(nums[l2++]);

        for(int j =l;j<=r;j++) nums[j]=arr[j-l];
        return res;
    }
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        this->diff=diff;
        int n = nums1.size();
        for(int i =0;i<n;i++){
            nums1[i]-=nums2[i];
        }
        return merge(nums1,0,n-1);
    }
};