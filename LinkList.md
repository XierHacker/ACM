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

最基本的单链表的操作就是创建一个单链表了,这里假设我们有一个数组,我们想要通过这个数组建立单链表
```c++
//根据已经有的数组创建链表,并且返回头结点地址
//type=0,表示尾插法.type=1,表示头插法
ListNode* createList(const std::vector<int>& v,int type)
{
    switch(type)
    {
        //尾插法
        case 0:
            {
                //创建头结点和一些必要的指针
                ListNode *head,*s,*r; //s指向新申请的节点,r指向终端节点
                head=new ListNode;
                head->next=nullptr;
                r=head;    //r指向头结点,因为此时头结点就是终端节点

                //遍历vector创建链表
                for(int i=0;i<v.size();i++)
                {
                    s=new ListNode;
                    s->value=v[i];
                    r->next=s;  //
                    r=s;
                }
                r->next=nullptr;

                return head;
            }

        //头插法
        case 1:
            {
                //创建头结点和一些必要的指针
                ListNode *head,*s;
                head=new ListNode;
                head->next=nullptr;

                for(int i=0;i<v.size();i++)
                {
                    s=new ListNode;
                    s->value=v[i];
                    s->next=head->next;
                    head->next=s;
                }
                return head;
            }
    }
}

```

建立起一个链表之后,我们很常用的一个操作就是在链表后面插入一个元素,
思路也很简单,遍历到链表最后,插入就行了.
```c++
//尾部插入一个元素(头结点有可能改变)
void addToTail(ListNode* &head,int value)
{
    //为新值创建空间
    ListNode* s=new ListNode;
    s->value=value;
    s->next=nullptr;

    //如果头结点本身就是空值
    if(head==nullptr)
    {
        head=s;
    }
    else
    {
        ListNode* r=head;
        //往下遍历
        while(r->next!=nullptr)
        {
            r=r->next;
        }
        r->next=s;
    }
}
```

然后就是在链表中查找某个元素了.我们这里给出一个实现,能够找到元素的前一个位置
这么做的原因,是因为我们一般查找之后还有其他的操作,这样做方便很多.
```c++
//找到某个值,返回第一次出现的前一个节点地址
ListNode* find_value(ListNode* head,int value)
{
    //判断head是否是空
    if(head==nullptr)
    {
        return nullptr;
    }

    ListNode* r=head;
    while(r->next!=nullptr)
    {
        if(r->next->value==value)
        {
            return r;
        }
        r=r->next;
    }
    return nullptr;
}
```
有了插入操作,就有删除操作,怎么删除某个值的节点呢?这个时候,首先就需要用到我们前面说的查找
的方式,查找可以知道某个值是不是在链表中,它的位置是在哪里.(这个时候就体现了返回前一个位置的优越性了)
```c++
//删除某个值,并且返回是否成功
bool remove_value(ListNode* head,int value)
{
    //先找到某个值
    ListNode* p=find_value(head,value);
    //值不存在
    if(p==nullptr)
        return false;
    else
    {
        ListNode* r=p->next;
        p->next=p->next->next;
        delete r;
        return true;
    }
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
void reverse_traversal(ListNode* head)
{
    //判断为空
    if(head==nullptr||head->next==nullptr)
        return ;
    std::stack<ListNode*> nodes;
    //因为头结点不存储元素
    ListNode* r=head->next;
    //往stack里面存节点地址
    while(r!=nullptr)
    {
        nodes.push(r);
        r=r->next;
    }

    //打印
    while(!nodes.empty())
    {
        r=nodes.top();
        std::cout<<r->value<<" ";
        nodes.pop();
    }
    std::cout<<std::endl;
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

