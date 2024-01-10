        // acm模式输入输出
        // https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142^v99^pc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187
        #include<iostream>
        #include<vector>
        using namespace std;
        int main(){
            class Solution{
            public:
                int search(vector<int>& nums, int target){
                    // [) 左闭右开，所以右取不到
                    int left = 0, right = nums.size();
                    // 当left== right，区间[left, right)没效了，所以用 < 
                    while (left < right){
                        int mid = left + (right - left) / 2; // 防止溢出, 没有直接(right+left)/2
                        if (nums[mid] > target){
                            // target 在左半， 动right; 因为[) right取不到，mid已经比过了，所以right= mid
                            right = mid;
                        }
                        else if (nums[mid] < target){
                            // target在右半
                            left = mid + 1;
                        }
                        else
                            return mid;
                    }
                    return -1;   
                }
            };

            class Solution2{
            public:
                int search(vector<int>& nums, int target){
                    // [] 左闭右闭，所以右可以取到，所以是-1，如果不减1，根本下标取不到
                    int left = 0, right = nums.size() - 1;
                    // 这里自己做的时候错了！！！！ 
                    // 当left==right，区间[left, right]依然有效，所以用 <= 可以取== 
                    while (left <= right){
                        int mid = left + (right - left) / 2; // 防止溢出, 没有直接(right+left)/2
                        if (nums[mid] > target){
                            // target 在左半， 动right; 因为[] right取得到，mid已经比过了，所以right= mid-1
                            right = mid -1;
                        }
                        else if (nums[mid] < target){
                            // target在右半
                            left = mid + 1;
                        }
                        else
                            return mid;
                    }
                    return -1;   
                }
            };

            vector<int> nums;
            int num;
            while(cin >> num){
                nums.push_back(num);
                if(getchar() == '\n'){
                    break;
                }
            }

            int target;
            cin>>target;

            cout<< Solution().search(nums,target) << ' ' << Solution2().search(nums,target) << endl;
            return 0;
        }