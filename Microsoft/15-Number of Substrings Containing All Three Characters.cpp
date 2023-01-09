class Solution {
public:
    int numberOfSubstrings(string &s) {
        int i =0,n=s.size();
        vector<int> count(3,0);
        int ans=0;
        for(int j=0;j<n;j++){
            count[s[j]-'a']++;
            while(count[0] && count[1] && count[2]){
                --count[s[i++]-'a'];
            }
            ans+=i;
        }
        return ans;
    }
};