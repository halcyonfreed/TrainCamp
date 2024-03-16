class Solution{
private:
// 函数用引用传参
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder){
        // 2 结束条件
            // 2.1 先根据后序数组最后一个
        if(postorder.size()==0) return nullptr;

        // 先把root根节点造好！！
        int rootValue=postorder[postorder.size()-1];
        TreeNode* root=new TreeNode(rootValue);

            // 2.2 结束条件
        if(postorder.size()==1) return root; //构造树结束

        // 3 单层，开始互相切
        // 先切中序 中序里找切割点
        int delimiterIndex;
        for(delimiterIndex=0; delimiterIndex<inorder.size();delimiterIndex++){
            if(inorder[delimiterIndex]==rootValue) break;
        }
        vector<int> leftInorder(inorder.begin(),inorder.begin()+delimiterIndex); //统一左闭右开
        vector<int> rightInorder(inorder.begin()+delimiterIndex+1,inorder.end());

        // 用长度 切后序左右
        
        // postorder.resize(postorder.size() - 1); //可以不写
        vector<int> leftPostorder(postorder.begin(),postorder.begin()+leftInorder.size());
        vector<int> rightPostorder(postorder.begin()+leftInorder.size(),postorder.end()-1);

        /*
        自己学着写log
        cout << "----------" << endl;

        cout << "leftInorder :";
        for (int i : leftInorder) {
            cout << i << " ";
        }
        cout << endl;

        cout << "rightInorder :";
        for (int i : rightInorder) {
            cout << i << " ";
        }
        cout << endl;

        cout << "leftPostorder :";
        for (int i : leftPostorder) {
            cout << i << " ";
        }
        cout << endl;
         cout << "rightPostorder :";
        for (int i : rightPostorder) {
            cout << i << " ";
        }
        cout << endl;
        */


        // 套娃
        root->left= traversal(leftInorder,leftPostorder);
        root->right=traversal(rightInorder,rightPostorder);

        return root; //这行不加会怎么样:报错没有返回值，如果不满足上面两种if条件，就不返回值了
        
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        // if (inorder.size() == 0 || postorder.size() == 0) return NULL;//可以不写！！！
        return traversal(inorder,postorder);
    }
};


// 优化版，不用创建新的vector，inorder,postorder始终不变，只是不停改取的范围
// 妙啊

class Solution{
private:
    TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& postorder, int postorderBegin, int postorderEnd){
        // 2结束条件
        // inorder始终不变，begin和end动态变化
        // 先通过后序切中序，先判后序
        if(postorderBegin==postorderEnd) return nullptr;

        int rootValue=postorder[postorderEnd-1];
        TreeNode* root=new TreeNode(rootValue);

        if(postorderEnd-postorderBegin==1) return root;

        // 开始切，先找中序切割点
        int delimiterIndex;
        for(delimiterIndex=;delimiterIndex<inorderEnd;delimiterIndex++){
            if(inorder[delimiterIndex]==rootValue) break;
        }
        // 左闭右开
        int leftInorderBegin=inorderBegin;
        int leftInorderEnd=delimiterIndex;

        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        // 切后序
        int leftPostorderBegin =  postorderBegin;
        int leftPostorderEnd = postorderBegin+ (delimiterIndex - inorderBegin);
        int rightPostorderBegin = postorderBegin + (delimiterIndex - inorderBegin);
        int rightPostorderEnd = postorderEnd - 1; // 排除最后一个元素，已经作为节点了

        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd,  postorder, leftPostorderBegin, leftPostorderEnd);
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
