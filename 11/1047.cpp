
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;
class Solution {
public:
    string removeDuplicates(string S) {
        // 法一专门弄个stack，再result转成string
        stack<char> st;
        for(char s:S){
            if(st.empty() || st.top()!=s) st.push(s); // ||前后两个条件不可以调换
            else st.pop();
        }
        // 转成string不会
        string result="";
        while(!st.empty()){
            result+=st.top();
            st.pop(); //要pop！！
        }
        // return reverse(result.begin(),result.end()); //这种写法错 reverse() 函数返回的是一个空值（void），因此不能用作返回值
        reverse(result.begin(),result.end());
        return result;


        // 法二 不用stack，直接string
        string result;
        for(char s:S){        
            if(result.empty() || result.back()!=s) result.push_back(s);
            else result.pop_back();
        }       
        return result;
    }
};