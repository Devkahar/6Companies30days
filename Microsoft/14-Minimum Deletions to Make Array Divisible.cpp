#include <bits/stdc++.h>
class Solution {
    int gcd(int a, int b){if(b == 0){return a;} return gcd(b, a % b);}
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int c = numsDivide[0];
        for(int i =1;i<numsDivide.size();i++){
            c = gcd(c,numsDivide[i]);
        }
        sort(nums.begin(),nums.end());
        int ans =0;
        for(int i =0;i<nums.size();i++){
            if(c%nums[i]==0){
                break;
            }
            ans++;
        }
        if(ans==nums.size()) return -1;
        return ans;
    }
};