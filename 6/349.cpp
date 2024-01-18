#include<unordered_set>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 存交集结果
        unordered_set<int> result_set; // 无重复的
        // 先对1去重
        unordered_set<int> num_set(nums1.begin(),nums1.end()); // vector变set
        // 2和去重后的1比较，往结果加
        for(int num:nums2){
            if(num_set.find(num)!=num_set.end()){
                // num_set.find(num)如果没找到就会返回.end()，找到就返回指向元素的iterator
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(),result_set.end());
    }
};
int main(){
    // 输入
    int num1,num2;
    vector<int> nums1, nums2;
    while(cin>>num1){
        nums1.push_back(num1);
        if (getchar()=='\n') break;
    }
    while(cin>>num2){
        nums2.push_back(num2);
        if (getchar()=='\n') break;
    }

    vector<int> result;
    result=Solution().intersection(nums1,nums2);

    // 输出
    for(int num:result){
        cout<<num<<' ';
    }
    // for(int i=0;i<result.size();i++){
    //     cout<<result[i]<<' ';
    // }
    cout<<endl;
    return 0;
}