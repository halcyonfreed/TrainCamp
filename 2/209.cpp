#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // int result=nums.size()+1; //就是一个很大的数 用来检测没找到情况！！！ 默认长度
        int result=INT32_MAX;
        int sum=0; // 滑动窗口数值之和
        int i=0; // 滑动窗口起始位置
        int subLength=0; // 滑动窗口的长度

        for(int j=0; j<nums.size();++j){
            sum+=nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件 不是if
            while(sum>=target){
                // 更新minLen
                subLength=j-i+1; 
                result= subLength<result? subLength:result;

                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置），弹出old起始
            }
        }
        // return result==nums.size()+1? 0:result;
        return result==INT32_MAX? 0:result;
    }
};
int main(){
    int num,target;
    vector<int> nums;
    while(cin>>num){
        nums.push_back(num);
        if(getchar() == '\n') break;
    }

    cin>>target;
    cout<<Solution().minSubArrayLen(target,nums)<<endl;
    return 0;
}