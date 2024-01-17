#include<iostream>
#include<string>
#include<algorithm>
// 为了reverse
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0; i<s.size();i+=2*k){
            if(i+k>s.size()){
                reverse(s.begin()+i,s.end());   
            }
            else{
                reverse(s.begin()+i,s.begin()+i+k);
            }
        }
        return s;
    }
};
int main(){
    string words;
    cin>>words;
    int k;
    cin>>k;

    words=Solution().reverseStr(words,k);
    cout<<words<<endl;
    
    return 0;
}