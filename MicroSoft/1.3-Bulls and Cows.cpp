class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int,bool> mp,mp2;
        int n = guess.size();
        int x=0,y=0;
        for(int i =0;i<n;i++){
            if(secret[i]==guess[i]){
                mp[i]=1;
                mp2[i]=1;
                x++;
            }
        }
        for(int i =0;i<n;i++){
            if(mp.find(i)==mp.end()){
                for(int j=0;j<n;j++){
                    if(mp2.find(j)==mp2.end() && secret[i]==guess[j]){
                        y++;
                        mp2[j]=1;
                        break;
                    }
                }
            }
        }
        return to_string(x)+"A"+to_string(y)+"B";
    }
};