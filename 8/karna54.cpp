#include<iostream>
using namespace std;
// class Solution{
// public: 
//     void 
// };

int main(){
    string s;
    cin>>s;
    
    // 先统计数字个数
    int cnt=0; //必须初始化
    for(int i=0; i<s.size();i++){
        if (s[i]>='0' && s[i]<='9'){
            cnt++;
        }
    }
    
    int oldsize=s.size(); //要先存一下
    
    // 扩容 why 5?因为number 6个数字 而且本来数字那一位也被换
    s.resize(s.size()+5*cnt);
    for(int j=s.size()-1,i=oldsize-1; i<j;i--,j--){
        if (s[i]>='0' && s[i]<='9'){
            s[j]='r';
            s[j-1]='e';
            s[j-2]='b';
            s[j-3]='m';
            s[j-4]='u';
            s[j-5]='n';
            j-=5; //不用j-=6 因为for最后对i,j一起--
        }
        else{
            s[j]=s[i];
        }
    }
    
    cout<<s<<endl;
    return 0;
}