#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> res(n,vector<int>(n,0));

        int startx=0, starty=0;
        int loop=n/2,mid=n/2;

        int count=1;
        int offset=1;
        while(loop--){
            int i,j; //这里和官方不一样
            for(j=starty;j<n-offset;j++){
                res[startx][j]=count++;
            }
            for(i=startx;i<n-offset;i++){
                res[i][j]=count++;
            }
            for(;j>startx;j--){
                res[i][j]=count++;
            }
            for(;i>startx;i--){
                res[i][j]=count++;
            }
            startx++;
            starty++;

            offset++;
        }
        if(n%2) res[mid][mid]=count;
        return res;
    }
};

//官方题解
class Solution2{
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
        
        // 以圈为单位想问题
        int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
        int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
        int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
        int count = 1; // 用来给矩阵中每一个空格赋值
        int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
        int i,j;
        while (loop --) {
            // 这里很妙的 自己想不清的，i，j是while内全局变量
            i = startx;
            j = starty;
            // 下面开始的四个for就是模拟转了一圈，没办法左闭右闭，这样会重复
            // 模拟填充上行从左到右(左闭右开) 所以最后一个不能取，只能到n-2
            for (j = starty; j < n - offset; j++) {
                res[startx][j] = count++;// j到n-offset-1了最右
            }
            // 模拟填充右列从上到下(左闭右开)
            for (i = startx; i < n - offset; i++) {
                res[i][j] = count++; //j 最右，i最低了
            }
            // 模拟填充下行从右到左(左闭右开)
            for (; j > starty; j--) {
                res[i][j] = count++;// j最左，i最低
            }
            // 模拟填充左列从下到上(左闭右开)
            for (; i > startx; i--) {
                res[i][j] = count++;//j最左，i最上
            }

            // 左边往里缩，第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++;
            starty++;

            // 右边也往里缩！！offset 控制每一圈里每一条边遍历的长度
            offset += 1;
        }

        // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};
int main(){
    int n;
    cin>>n;
    vector<vector<int>> result;
    result=Solution().generateMatrix(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<< result[i][j]<<' ';
            // cout<< Solution().generateMatrix(n)[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
