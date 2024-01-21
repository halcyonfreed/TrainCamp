#include<string>
#include<vector>
#include<stack>
#include<iostream>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st; //中间结果
        for (int i=0; i<tokens.size();i++){
            cout<<tokens[i]<<' ';
            if (tokens[i]>="0" && tokens[i]<="9") st.push(stoll(tokens[i]));
            // else if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
            else{
                long long num1=st.top(); //先取再pop
                st.pop();

                long long num2=st.top(); 
                st.pop();

                if(tokens[i] == "+" ) st.push(num2+num1); 
                if(tokens[i] == "-" ) st.push(num2-num1); 
                if(tokens[i] == "*" ) st.push(num2*num1); 
                if(tokens[i] == "/" ) st.push(num2/num1);


                // 下面是要命的错误，num2和num1的顺序反了！！
                // cout<< num1 <<' '<< num2<< " ";
                // if(tokens[i] == "+" ) st.push(num1+num2); 
                // if(tokens[i] == "-" ) st.push(num1-num2); 
                // if(tokens[i] == "*" ) st.push(num1*num2); 
                // // if(tokens[i] == "/" ) {st.push(num1/num2); cout<<num1/num2<<' ';}              
            }
            cout<<st.top()<<endl;

        }
        // return st.top();
        int result=st.top();
        return result;
    }
};

int main(){
    string s;
    vector<string> words;
    while(cin>>s){
        words.push_back(s);
        if (getchar()=='\n') break;
    }
    cout<<Solution().evalRPN(words)<<endl;
    return 0;
}