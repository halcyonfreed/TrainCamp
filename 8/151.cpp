#include<iostream>
#include<string>
// #include<algorithm>
using namespace std;

class Solution{
public:
// 自己实现也可以！
    void reverse(string& s, int start, int end){
        // i=j要是再翻，没意义加也行！！ 左闭右闭[]
        for(int i=start,j=end; i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }

    void removeExtraSpaces(string& s){
        int slow=0;
        // i就是fast
        for(int i=0;i<s.size();++i){
            // if(s[i]!=' '){
            //     s[slow++]=s[i++];
            // }  //本来是这样的，遇到不是空格，就原地赋值,把fast的赋给slow
            
            
            // 妙啊！！！自己想不到，但是不能全删了，还要在单词之间通过手动加上空格
            // !!!!!!!!就是这里不会!!!!!!!!!!!!!!
            if(s[i]!=' '){
                if(s[slow]!=0) s[slow++]=' '; //开头不能加！先对slow加空格，然后对slow再加单词
                while(i<s.size() && s[i]!=' '){ //再从可空格往后加完这个单词。直到i=fast遇到下一个单词，妙自己想不到！！
                    s[slow++]=s[i++];
                }
            }
        }
    }

    string reverseWords(string s){
        removeExtraSpaces(s);
        reverse(s,0,s.size()-1);
        int start=0;
        for(int i=0;i<=s.size();i++){
            if(i==s.size()|| s[i]==' '){
                // 词尾翻转，或者单词结束
                reverse(s,start,i-1); //第一个从start=0开始，转第一个单词！！
                start=i+1; //i是空格
            }
        }
        return s;
    }
};