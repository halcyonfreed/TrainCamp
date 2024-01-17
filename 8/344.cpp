#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0,j=s.size()-1; i<=j;i++,j--){
            // i < s.size()/2我用的是i<=j也可以！！
            swap(s[i],s[j]);
        }
    }
};

int main(){
    // 输入vector
    char s;
    vector<char> words;
    while(cin>>s){
        words.push_back(s);
        if(getchar()=='\n') break;
    }

    Solution().reverseString(words);
    // 输出
    for(int i=0;i<words.size();i++){
        cout<<words[i]<<' ';
    }
    cout<<endl;
    return 0;
}