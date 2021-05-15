# 一.单向链表
## 1.1 基本概念
## 1.2 基本写法实现
基本的单链表的节点可以写作
```c++
struct ListNode
{
    int value;
    ListNode* next;
};
```
在leetcode中，单链表一般定义如下
```c++
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
```



最基本的单链表的操作就是创建一个单链表了,这里假设我们有一个数组,我们想要通过这个数组建立单链表
```c++
//根据已经有的数组创建链表,并且返回头结点地址,type=0,表示尾插法.type=1,表示头插法
ListNode *CreateListFromVector(const std::vector<int> &v, int type) {
    if (v.empty()) { return nullptr; }
    switch (type) {
        //尾插法
        case 0: {
            ListNode *head = new ListNode;
            head->next_node = nullptr;
            ListNode *r = head; //r指向头结点,因为此时头结点就是终端节点,且r不断变化
            //遍历vector创建链表
            for (int i = 0; i < v.size(); i++) {
                ListNode *temp_node = new ListNode;
                temp_node->value = v[i];
                r->next_node = temp_node;
                r = temp_node;
            }
            r->next_node = nullptr;
            return head;
        }
        //头插法
        case 1: {
            ListNode *head = new ListNode;
            head->next_node = nullptr;
            for(int i=0;i<v.size();i++)
            {
                ListNode* temp_node=new ListNode;
                temp_node->value=v[i];
                temp_node->next_node=head->next_node;
                head->next_node=temp_node;
            }
            return head;
        }
    }
}

```

建立起一个链表之后,我们很常用的一个操作就是在链表后面插入一个元素,思路也很简单,遍历到链表最后,插入就行了.
```c++
//链表尾部插入元素,其中头结点有可能改变
bool AddToTail(ListNode* &head,int value){
    ListNode* new_node=new ListNode;
    new_node->value=value;
    new_node->next_node= nullptr;

    //要是头节点本身是个nullptr
    if(head== nullptr){
        head=new_node;
        return true;
    }
    ListNode* temp_node=head;
    while(temp_node->next_node!= nullptr){
        temp_node=temp_node->next_node;
    }
    temp_node->next_node=new_node;
    return true;
}
```

然后就是在链表中查找某个元素了.我们这里给出一个实现,能够找到元素的前一个位置
这么做的原因,是因为我们一般查找之后还有其他的操作,这样做方便很多.
```c++
//查找链表中某个元素,并且返回这个元素的前一个元素的地址，要是找不到，返回nullptr
ListNode* FindValue(ListNode* head,int value){
    if(head== nullptr){return nullptr;}
    ListNode* temp_node=head;
    while(temp_node->next_node!= nullptr){
        if(temp_node->next_node->value==value){
            return temp_node;
        }
        temp_node=temp_node->next_node;
    }
    return nullptr;
}
```

有了插入操作,就有删除操作,怎么删除某个值的节点呢?这个时候,首先就需要用到我们前面说的查找
的方式,查找可以知道某个值是不是在链表中,它的位置是在哪里.(这个时候就体现了返回前一个位置的优越性了)
```c++
//删除链表中某个元素,删除成功返回true,否则返回false
bool DeleteValue(ListNode *head, int value) {
    if (head == nullptr) { return false; }
    ListNode *prev_node = FindValue(head, value);
    if (prev_node == nullptr) { return false; }

    //delete node
    ListNode* temp_node=prev_node->next_node;
    prev_node->next_node=prev_node->next_node->next_node;
    delete temp_node;
    return true;
}
```

# 二.双向链表







# 三.循环链表

# 四.一些题目
## 4.1从尾到头打印链表
一般来说,我们遍历链表都是从头到尾遍历的,而题目是从尾到头遍历链表.我们怎么实现呢?
当然这个题目是不允许改变链表结构的.其实也挺容易的.就先遍历,把遍历得到的地址放入一个栈内,
利用栈**先进后出**的性质来做就行了.
```c++
//从尾到头打印链表(反向遍历)
//反向打印链表
void ReverseTraversal(ListNode *head) {
    if (head == nullptr || head->next_node == nullptr) { return; }
    std::stack<ListNode *> storage;
    ListNode *temp_node = head->next_node;
    while (temp_node->next_node != nullptr) {
        storage.push(temp_node);
        temp_node = temp_node->next_node;

    }
    std::cout << "Reverse Traversal:";
    while (!storage.empty()) {
        temp_node = storage.top();        //获得最上面元素
        std::cout << temp_node->value << " ";
        storage.pop();                  //弹出元素
    }
    std::cout << std::endl;
}
```

## 4.2 在O(1)时间删除链表节点

## 4.3 链表中倒数第K个节点
在一个单链表中,要得到倒数第K个节点的话,要么从前往后遍历一次,得到节点总数,
然后通过数学n-k+1个节点再遍历一次,

**要么就是使用两个指针进行遍历**,遍历思想很简单,首先一个指针向前走到K个节点位置,
然后另外一个指针开始和这个指针一起遍历.中间的间隔总是K.当前一个指针到最后一个节点时,
后面才遍历的指针自然指向得是倒数第K个节点.

然后,具体写代码的时候,需要考虑很多的情形.**不要漏掉一些细节**
```c++
//倒数第K个节点
ListNode* re_k_th_node(ListNode* head,int k)
{
    //head为空和k为0没有意义
    if(head==nullptr||k==0)
        return nullptr;

    //两个指针
    ListNode* ahead=head;
    ListNode* behind=head;

    //前面这个指针先走到K
    //要是出现了过早出现nullptr的情况,表示数量不够K
    for(int i=1;i<=k-1;i++)
    {
        if(ahead->next!=nullptr)
            ahead=ahead->next;
        else
            return nullptr;
    }

    //一起遍历到末尾
    while(ahead->next!=nullptr)
    {
        ahead=ahead->next;
        behind=behind->next;
    }

    return behind;
}
```



## 4.4 反转链表
定义一个函数,输入一个链表的头结点,反转该链表,并输出反转后链表的头结点.
```c++
//反转链表,并且返回新的头结点地址
ListNode* reverseList(ListNode* head)
{
    //判断是否有效
    if(head==nullptr)
        return nullptr;

    ListNode* newHead=nullptr; //新的头结点
    ListNode* r=head; //往下遍历的的指针
    ListNode* pre=nullptr; //保存前一个地址

    while(r!=nullptr)
    {
        ListNode* pNext=r->next; //保存后一个地址

        //要是到最后的节点了,那么这个地址就是新的头结点地址
        if(r->next==nullptr)
            newHead=r;

        //往前指
        r->next=pre;

        //更新
        pre=r;
        r=pNext;

    }
    return newHead;
}
```

## 4.5 合并两个排序链表
传入两个有序链表的头结点,然后输出合并之后新链表的头结点.
用递归的方式来做就行
```c++
//合并两个有序链表
ListNode* mergeList(ListNode* head1,ListNode* head2)
{
    //判断为空的情况
    //要是两个都为空,返回也是空
    if(head1==nullptr||head1->next==nullptr)
        return head2;
    if(head2==nullptr||head2->next==nullptr)
        return head1;

    ListNode* mergedHead=nullptr;

    //用递归来完成
    if(head1->next->value<head2->next->value)
    {
        mergedHead=head1;
        mergedHead->next=mergeList(head1->next,head2);
    }
    else
    {
        mergedHead=head2;
        mergedHead->next=mergeList(head1,head2->next);
    }
    return mergedHead;
}
```

## 4.6 判断链表中是否有环
这里我们可以想到有三种解决的方法。

第一种方法
>**将所有的遍历过的节点用某个结构存储起来，然后每遍历一个节点，都在这个结构中查找是否遍历过，如果找到有重复，则说明该链表存在循环；如果直到遍历结束，则说明链表不存在循环。**
这个结构我们可以使用hash来做，hash中存储的值为节点的内存地址，这样查找的操作所需时间为O(1)，遍历操作需要O(n)，hash表的存储空间需要额外的O(n)。所以整个算法的时间复杂度为O(n)，空间复杂度为O(n)。

第二种方法
>比较的特别，是使用反转指针的方法，每过一个节点就把该节点的指针反向。
当有环的时候，最后指针会定位到链表的头部，如果到最后，都没有再到头部，那说明链表不存在循环。
这个方法会破坏掉链表，所以如果要求是不能破坏链表的话，我们最后就还需要反转一下，再将链表恢复。
这个方法使用的空间复杂度为O(1)，其实是使用了3个指针，用于进行反转。同时，时间复杂度为O(n)。

第三种方法,同时也是面试官大多想要得到的答案，就是快慢指针。

>快指针pf(f就是fast的缩写)每次移动2个节点，慢指针ps(s为slow的缩写)每次移动1个节点，如果快指针能够追上慢指针，那就说明其中有一个环，否则不存在环。
这个方法的时间复杂度为O(n)，空间复杂度为O(1)，实际使用两个指针。
>

## 4.7 链表求和
用单链表来表示一个整数，最高位为最后一个节点。写出两个整数相加的的方法,并且返回这个新链表头（两个链表倒叙求和）
```asm
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```
代码如下:
```c++
//链表整数相加
ListNode* AddTwoNumbers(ListNode* head1,ListNode* head2){
    if((head1== nullptr)&&(head2== nullptr)){return nullptr;}
    ListNode* new_head=new ListNode;
    new_head->next_node= nullptr;
    ListNode* temp1=head1->next_node;
    ListNode* temp2=head2->next_node;
    int d=0;        //进位
    while(temp1||temp2||d){
        int sum=0;
        //求和
        sum+=(temp1?temp1->value:0);
        sum+=(temp2?temp2->value:0);
        sum+=d;
        d=sum/10;
        sum%=10;

        //头插法创建链表
        ListNode* new_temp=new ListNode;
        new_temp->value=sum;
        new_temp->next_node=new_head->next_node;
        new_head->next_node=new_temp;

        //记得转移到下一个节点,不然死循环
        temp1=temp1?temp1->next_node: nullptr;
        temp2=temp2?temp2->next_node: nullptr;
    }
    return new_head;
}
```





## LeetCode高频链表题目





### leetcode206 反转链表
```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //异常条件
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* current_node=head;
        ListNode* prev_node=nullptr;
        ListNode* new_head=nullptr;
        
        while(current_node!=nullptr){
            if(current_node->next==nullptr){
                new_head=current_node;
            }
            ListNode* temp_node=current_node->next;
            current_node->next=prev_node;
            prev_node=current_node;
            current_node=temp_node;
        }
        return new_head;
    }
};

```
使用的就是双指针的策略。

![](https://pic.leetcode-cn.com/7d8712af4fbb870537607b1dd95d66c248eb178db4319919c32d9304ee85b602-%E8%BF%AD%E4%BB%A3.gif)

题解如下：
[**动画演示+多种解法 206. 反转链表**](https://leetcode-cn.com/problems/reverse-linked-list/solution/dong-hua-yan-shi-206-fan-zhuan-lian-biao-by-user74/)


### leetcode160 相交链表
```c++
class Solution {
public:
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //异常条件
        if(headA==nullptr || headB==nullptr){
            return nullptr;
        }
    
        ListNode* A=headA;
        ListNode* B=headB;
        while(A!=B){
            A=A!=nullptr?A->next:headB;
            B=B!=nullptr?B->next:headA;
        }
        return A;
    }
};

```



题解[**160. 相交链表（双指针，清晰图解）**](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/intersection-of-two-linked-lists-shuang-zhi-zhen-l/)


### leetcode21 合并有序链表
```c++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //为空的边界处理
        if(l1==nullptr)    {return l2;}
        if(l2==nullptr)    {return l1;}

        ListNode* merge_head=nullptr;

        if(l1->val<=l2->val){
            merge_head=l1;
            merge_head->next=mergeTwoLists(l1->next,l2);
        }else{
            merge_head=l2;
            merge_head->next=mergeTwoLists(l1,l2->next);
        }
        return merge_head;
    }
};

```

题解：简单的递归。


### leetcode 141 环形链表

```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
```

题解：快慢指针
![](https://pic.leetcode-cn.com/1617159413-iCDVNF-141.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8.gif)


### leetcode2 两数相加

```c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result=new ListNode;
        ListNode* record;
        int d=0;
        int i=0;
        //add
        while(l1!=nullptr||l2!=nullptr||d){
            int sum=0;
            sum+=(l1?l1->val:0)+(l2?l2->val:0)+d;
            d=sum/10;       //十位
            int num=sum%10; //个位
            
            //创建链表
            ListNode* temp_node=new ListNode;
            temp_node->val=num;
            if(i==0){
                result=temp_node;
                result->next=nullptr;
                record=result;
            }
            else{
                record->next=temp_node;
                record=temp_node;
            }
            l1=l1?l1->next:nullptr;
            l2=l2?l2->next:nullptr;
            ++i;
        }
        record->next=nullptr;
        return result;
    }
};

```

题解：两数相加，注意进位就行。