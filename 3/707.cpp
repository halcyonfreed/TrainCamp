

class MyLinkedList {
public:
    // 定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };

    // 初始化链表
    MyLinkedList() {
        _dummyHead = new LinkedNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        _size = 0;
    }

    int get(int index){
        if(index>(_size-1) || index<0) return -1;

        // 先找到位置，链表不用for找位置，用cur然后cur->next非空来找位置
        LinkedNode* cur=_dummyHead->next;
        while(index--){
            cur=cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val){
        // 不用找
        LinkedNode* newhead=new LinkedNode(val);
        newhead->next=_dummyHead->next; //这里错了漏->next
        _dummyHead->next=newhead; //新投
        _size++;
    }

    void addAtTail(int val){
        LinkedNode* newnode=new LinkedNode(val);

        // 找到尾巴先！
        LinkedNode* cur=_dummyHead;
        while(cur->next){
            // 养成习惯，最后写while里条件，最后一个停下所以cur->next
            cur=cur->next;
        }
        cur->next=newnode;
        _size++;
    }

    void addAtIndex(int index, int val){
        // 情况太多了！！
        if (index>_size) return; //不加
        if(index<0) index=0;

        LinkedNode* newNode=new LinkedNode(val);
        // 找到位置先！
        LinkedNode* cur=_dummyHead;
        while(index--){
            cur=cur->next;
        }
        // 注意顺序，自己画个图就懂了！！！
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
        
    void deleteAtIndex(int index){
        if (index >= _size || index < 0) {
            return;
        }

        // 先找位置，停在index前一个，因为借助前一个删掉index这个；但是因为cur初始是dummyHead，而且index不是下标，就是实际第index个，从1开始
        LinkedNode* cur=_dummyHead;
        while(index--) {
                cur = cur ->next;
            }
            LinkedNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
            //delete命令指示释放了tmp指针原本所指的那部分内存，
            //被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
            //如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
            //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
            tmp=nullptr;
            _size--;
        }
// 超时妈的
    void printLinkedList() {
        // 和答案不一样
        LinkedNode* cur = _dummyHead->next;
        while (cur){
            cout<<cur->val<<' ';
            cur=cur->next;
        }
        cout<<endl;
    }
private:
// 一定要写啊啊啊啊，不然会报错内部变量，扔到private里保护a起来！
    int _size;
    LinkedNode* _dummyHead;
};
