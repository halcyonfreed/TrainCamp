#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t){
        // 确定会有多少长度 长26, 元素0
        int cnt[26]={0};
        // 统计次数
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']+=1;
        }
        for(int i=0;i<t.size();i++){
            cnt[t[i]-'a']-=1;
        }
        for(int i=0; i<26;i++){
           cout<<cnt[i]; 
        }
        cout<<endl;
        // 判断，有0就停 用c++11特性
        for(int i=0; i<26;i++){
            if (cnt[i]!=0) return false;
        }
        return true;
    }
};

int main(){
    string s,t;
    cin>>s>>t;
    cout<<Solution().isAnagram(s,t)<<endl;
    return 0;
}