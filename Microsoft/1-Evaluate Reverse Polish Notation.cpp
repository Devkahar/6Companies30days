class Solution {
    
    bool isOperator(string &s){
        vector<string> opr= {"+","-","*","/"};
        for(auto it: opr){
            if(it==s) return 1;
        }
        return 0;
    }
    int performOpr(int a,int b,string &opr){
        if(opr=="+"){
            return a+b;
        }else if(opr=="-"){
            return a-b;
        }else if(opr=="*"){
            return a*b;
        }
        return a/b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for(int i =0,num1,num2;i<n;i++){
            if(!isOperator(tokens[i])){
                st.push(stoi(tokens[i]));
            }else{
                num1=st.top();
                st.pop();
                num2=st.top();
                st.pop();
                st.push(performOpr(num2,num1,tokens[i]));
            }
        }
        return st.top();
    }
};
//Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
