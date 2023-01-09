class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> available,vacancy;
        int n = nums.size();
        nums.push_back(nums[n-1]+1);
        for(int i =0;i<n;i++){
            available[nums[i]]++;
        }
        for(int i =0;i<n;i++){
            if(available[nums[i]]>0){
                if(vacancy[nums[i]]>0){
                    available[nums[i]]--;
                    vacancy[nums[i]]--;
                    vacancy[nums[i]+1]++;
                }
                else if(available[nums[i]+1]>0 && available[nums[i]+2]>0){
                    available[nums[i]]--;
                    available[nums[i]+1]--;
                    available[nums[i]+2]--;
                    vacancy[nums[i]+3]++;
                }
                else return 0;
            }
        }
        return 1;
    }
};