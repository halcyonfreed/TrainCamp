

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> map; //存储访问过的元素及其下标
        for(int i=0; i<nums.size();i++){
            auto iter=map.find(target-nums[i]); 
            //auto自动推导变量的类型 返回一个std::unordered_map<int,int>::iterator迭代器类型
            // 比如nums[0]=2; 找7有吗，如果找到了这里是7，返回7对应的second是值就是下标！！
            if(iter!=map.end()) return {iter->second,i};
            

            map.insert(pair<int,int>(nums[i],i)); //没找到配对的，就把访问过的元素和下标放进去
            // pair<int,int> 是 C++ STL 中的一个模板类，表示一个由两个元素组成的有序对。
        }
        return {}; //没有
    }
};