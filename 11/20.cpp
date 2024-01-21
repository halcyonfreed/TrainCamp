#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string S) {
        if(S.size()%2!=0) return false;
        stack<char> st;
        // string的遍历 我不会用，for
        for(char s :S)
        {

            // 处理左括号
            if (s=='{')  st.push('}'); //技巧，不直接压左括号
            else if (s=='(')  st.push(')');
            else if (s=='[')  st.push(']');


            // ------处理右括号
            //数量一样但是对不上；右括号多
            // else if(st.top()!=s  || st.empty()) return false;  //这样会非法 因为st可能本身是empty，顺序很重要！！！
            else if(st.empty() || st.top()!=s) return false;  //这样会非法 因为st可能本身是empty，顺序很重要！！！
            else st.pop(); //这行漏了
        }
        // 还剩下左括号多了
        return st.empty();
    }
};
int main(){
    string s;
    cin>>s;
    cout<<Solution().isValid(s)<<endl;
    return 0;
}