# 一.树的概念
## 1.1 树的定义

## 1.2 一些基本术语
对于一般的树，你需要掌握的概念有：
>**结点**:叶子结点（度为0),非叶子结点（度不为0）

>**结点的度**:分支个数

>**树的度**:结点度中的最大值

>**孩子**:结点子树的根

>**兄弟**:同一双亲的孩子之间互为兄弟

>**祖先**:从根到某个结点路径上面的所有结点，都是这个结点的祖先

>**树的高度/深度**:树中结点的最大层次

>**结点的高度/深度** 结点深度是从根节点算起的,根节点深度是1;结点高度是从最底层的叶子结点算起的,最底层叶子结点的高度是1.

理解一下就行了，不要死记硬背

# 二.二叉树
## 2.1 二叉树定义
定义：二叉树的本质肯定也还是树，将一般的树加上一些限制条件之后，就得到二叉树了。
>每个节点只能够有两颗子树（二叉树中节点的度只能够为0,1,2）
子树有左右之分，不能够颠倒

>也就是说,二叉树由根,左子树,右子树组成简写为(D,L,R)



## 2.2 常见术语
**满二叉树**:一棵二叉树中，要是所有的分支结点都有左孩子和右孩子，且叶子结点都集中在二叉树的最下面一层。如下图
![这里写图片描述](http://img.blog.csdn.net/20170303145257492?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQveGllcmhhY2tlcg==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

上面那个也不用硬背下来，你看上面的图可以通俗理解为，就是所有的“位置”都满了，该有孩子的都有了，所以叫做满二叉树。

**完全二叉树**:把一个满二叉树`从右至左`，`从下到上`，`挨个`删除结点所得到的树。如下图

![这里写图片描述](http://img.blog.csdn.net/20170303145904950?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQveGllcmhhY2tlcg==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

从上面看，不是按照规定的要求删结点的，跳着删除的，都不算是完全二叉树。

## 2.3 二叉树存储结构
```c++
struct BTNode
{
    int value;
    BTNode* lchild;
    BTNode* rchild;
};
```
## 2.4二叉树遍历
之所以把二叉树的遍历放在这么前来讲,是因为你只有遍历一棵树才能够
得到这棵树的完整信息,同时,遍历一棵树是其他很多操作的基本步骤.

常见的二叉树遍历算法有三种:分别是**先序遍历**,**中序遍历**和**后序遍历**
下面分别介绍这几种遍历方式.

### Ⅰ.先序遍历
先序遍历是一种递归的遍历方法.如下
>访问根节点

>先序遍历左子树

>先序遍历右子树

简单点来表示就是DLR.
```C++
//先序遍历二叉树
void pre_order(BTNode* root)
{
    if(root!=nullptr)
    {
        //访问根节点
        std::cout<<root->value<<" ";

        //先序遍历左子树
        pre_order(root->lchild);

        //先序遍历右子树
        pre_order(root->rchild);
    }
}

```

### Ⅱ.中序遍历
>中序遍历左子树

>访问根节点

>中序遍历右子树

简单点来表示就是LDR.
```C++
//中序遍历二叉树
void in_order(BTNode* root)
{
    if(root!=nullptr)
    {
        //中序遍历左子树
        in_order(root->lchild);
        //访问根节点
        std::cout<<root->value<<" ";
        //中序遍历右子树
        in_order(root->rchild);
    }
}

```
上面是中序遍历的递归思想,是非常简单直接的.符合人的思维习惯.同时,
中序遍历还有非递归的遍历思想.算法过程为:

步骤1:
>要是该节点有左孩子,那么该节点入栈.

>要是该节点没有左孩子,访问该节点.并且找右子树

步骤2:
>如果该节点有右子树,那么对于右子树重复步骤1.

>如果结点没有右子树(结点访问完毕),根据栈顶指示回退,访问栈顶元素,并访问栈顶元素右子树

```c++
//中序遍历二叉树(非递归形式)
//下面相当于步骤1
BTNode* goLeft(BTNode* root,std::stack<BTNode*> &s)   //一直往左子树走,直到得到可以访问的结点
{
    //边界条件[判断
    if(root==nullptr)
        return nullptr;

    //一直往左走,要是root一直有左孩子,那么就root入栈.
    while(root->lchild!=nullptr)
    {
        s.push(root);
        root=root->lchild;
    }

    //当root没有左孩子了,就返回root
    return root;
}
void in_order2(BTNode* root)
{
    BTNode* t=nullptr;
    //存储栈
    std::stack<BTNode*> s;

    //一直往左直到没有左孩子
    t=goLeft(root,s);

    while(t!=nullptr)
    {
        //输出该节点的内容
        std::cout<<t->value<<" ";

        //要是t有右子树,重复步骤1
        if(t->rchild!=nullptr)
        {
            t=goLeft(t->rchild,s); //右子树中找到中序遍历起点
        }
        else if(!s.empty())     //要是t没有右子树,栈不为空
        {
            t=s.top();
            s.pop();
        }
        else                    //要是t没有右子树,栈为空
        {
            t=nullptr;          //退出循环
        }
    }
}
```
### Ⅲ.后序遍历

>后序遍历左子树

>后序遍历右子树

>访问根节点

简单点来表示就是LRD.
```C++
//后序遍历二叉树
void post_order(BTNode* root)
{
    if(root!=nullptr)
    {
        post_order(root->lchild);
        post_order(root->rchild);
        std::cout<<root->value<<" ";
    }
}

```

### Ⅳ.广度遍历二叉树(逐层遍历)
逐层遍历的思想很简单，就是一层一层的遍历节点。一层遍历完成然后到下一层。
逐层遍历的规律也很简单，当遍历一个节点的时候，要是这个节点有子节点，该节点的子节点放在队列的末尾，
接下来从队列的头部取出节点，重复之前的操作。直到队列中所有节点都被遍历为止

```c++
//逐层遍历二叉树
void level_traversal(BTNode* root)
{
    //意外判断
    if(root==nullptr)
        return ;

    //存储节点指针
    std::deque<BTNode*> Queue;
    Queue.push_back(root);

    while(Queue.size())
    {
        BTNode* temp_Node=Queue.front();

        //打印头部(相当于遍历过了)
        std::cout<<temp_Node->value<<" ";
        //弹出头部
        Queue.pop_front();

        //要是有左边的话，存储左边
        if(temp_Node->lchild)
            Queue.push_back(temp_Node->lchild);
        //要是有右边的话，存储右边
        if(temp_Node->rchild)
            Queue.push_back(temp_Node->rchild);
    }
    std::cout<<std::endl;

}
```






## 2.5 二叉树常见操作
### Ⅰ.计算叶子结点个数
思路很简单,就是左右子树都是`nullptr`的就是叶子结点了.递归的遍历每一个结点
然后判断是否是叶子结点就行.
```c++
//计算叶子结点数量
//这里本身是按照先序遍历来的
void count_leaf(BTNode* root,int& sum)
{
    if(root!=nullptr)
    {
        //左右子树都是空,说明是叶子结点
        if((root->lchild==nullptr)&&(root->rchild==nullptr))
        {
            ++sum;
            std::cout<<root->value<<" ";
        }
        count_leaf(root->lchild,sum);
        count_leaf(root->rchild,sum);
    }
}
```

### Ⅱ.计算树的深度
计算树的深度,也是递归遍历左右子树深度,取最大的就行.
```c++
//计算树的深度
int getDepth(BTNode* root)
{
    //边界条件
    if(root==nullptr)
        return 0;

    int LD=getDepth(root->lchild);
    int RD=getDepth(root->rchild);
    return std::max(LD,RD)+1;
}
```

### Ⅲ.拷贝一棵树
依旧是递归的方式来分别拷贝左子树,右子树,和根节点,注意根节点的指向问题就行.
```c++
//拷贝一棵二叉树,并且返回根节点
BTNode* copyTree(BTNode* root)
{
    BTNode* newRoot=nullptr;
    BTNode* L_P=nullptr;
    BTNode* R_P=nullptr;

    //先copy左子树
    if(root->lchild!=nullptr)
    {
        L_P=copyTree(root->lchild);
    }

    //copy右子树
    if(root->rchild!=nullptr)
    {
        R_P=copyTree(root->rchild);
    }

    //弄出跟结点
    newRoot=new BTNode;
    newRoot->lchild=L_P;
    newRoot->rchild=R_P;
    newRoot->value=root->value;

    return newRoot;
}

```


### Ⅳ.创建二叉树
创建二叉树的方法有很多种,这里介绍接种常见的创建二叉树的方法.

**(1)`#`号法**

通过给定一个带有井号的遍历序列,可以确定一棵树.下面以先序遍历的为例子,创建一棵树
.


**(2)通过两种遍历序列来创建二叉树**

一般来说，给定了前序遍历和中序遍历，或者后序遍历和中序遍历，就能够还原一颗二叉树。

下面以前序遍历和中序遍历来还原一颗二叉树
```c++
//通过前序遍历和中序遍历来创建一颗树
//这个函数是创建树的核心递归函数(传入的是迭代器)
BTNode* construct_core(std::string::iterator pre_order_begin,
                       std::string::iterator pre_order_end,
                       std::string::iterator in_order_begin,
                       std::string::iterator in_order_end)
{
    //前序遍历序列的第一个数字是根节点的值
    BTNode* root=new BTNode;
    root->value=*pre_order_begin;
    root->lchild=root->rchild=nullptr;

    //边界条件，这个时候只有一个节点了
    if(pre_order_begin==pre_order_end)
    {
        if((in_order_begin==in_order_end)&&(*pre_order_begin==*in_order_begin))
            return root;
        else
        {
            std::cout<<"invalid input"<<std::endl;
            return nullptr;
        }
    }


    //中序遍历中找到根节点的值
    auto temp_itor=in_order_begin;
    while((temp_itor<=in_order_end) && (*temp_itor!=root->value))
    {
        ++temp_itor;
    }

    if((temp_itor==in_order_end) && (*temp_itor!=root->value))  //意外判断
    {
        std::cout<<"invalid input"<<std::endl;
        return nullptr;
    }


    int left_length=temp_itor-in_order_begin; //中序遍历序列判断左子树长度

    auto left_pre_order_end=pre_order_begin+left_length; //左子树的末端迭代器

    if(left_length>0)
    {
        //构建左子树
        root->lchild=construct_core(pre_order_begin+1,left_pre_order_end,in_order_begin,temp_itor-1);
    }
    if(left_length<pre_order_end-pre_order_begin)
    {
        //构建右子树
        root->rchild=construct_core(left_pre_order_end+1,pre_order_end,temp_itor+1,in_order_end);
    }
    return root;
}

//这里直接传入一个先序遍历的序列和一个中序遍历的序列就行了
BTNode* construct_tree(std::string& PreOrder,std::string& InOrder)
{
    //条件判断
    if(PreOrder.size()<=0||InOrder.size()<=0)  //没有元素的时候,那么不能够运行
    {
        std::cout<<"no element!"<<std::endl;
        return nullptr;
    }

    if(PreOrder.size()!=InOrder.size())        //要是前序遍历和中序遍历的元素个数不一样，那么也是错误的
    {
        std::cout<<"invalid input!"<<std::endl;
        return nullptr;
    }
    //调用递归函数
    return construct_core(PreOrder.begin(),PreOrder.end()-1,InOrder.begin(),InOrder.end()-1);
}

```


### Ⅴ.二叉树镜像
二叉树的镜像是非常常见的理解二叉树的一道题目，需要深刻理解二叉树的一些递归的性质。

二叉树镜像的规律也很简单。先前序遍历这棵树的每个节点，要是遍历到的节点有子节点，就交换他的两个子节点，
当交换完所有**非叶节点**的左右子节点后，就得到了树的镜像。
```c++
//翻转二叉树
void tree_mirror(BTNode* root)
{
    //边界判断
    if(root==nullptr)
        return ;
    if(root->lchild==nullptr && root->rchild==nullptr)  //没有左右孩子
        return ;

    //交换左右孩子
    std::swap(root->lchild,root->rchild);

    //对于左孩子递归使用反转函数
    if(root->lchild)
        tree_mirror(root->lchild);

    //对于右孩子递归使用翻转函数
    if(root->rchild)
        tree_mirror(root->rchild);
}
```


### Ⅵ.二叉树中和为某一值的路径
输入一棵树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。

这里有一些重要的关注点：首先，我们需要先序遍历的方式来访问各个结点（这样才能够保证根节点先被访问），
然后我们需要记录访问过得结点。同时，当从某个结点回退的时候，要删除记录中多余的结点。

这里有一个规律了，当用前序遍历的方式访问到某一个结点的时候，我们把这个结点添加到路径上面。并且累加该节点的值。
要是该节点为叶节点并且路径中节点总和为想要的值，那么当前路径复合要求，打印出来。
```c++
//二叉树中和为某一值的路径
void findPath(BTNode* root,int expectedSum,std::vector<int> path,int realSum)
{
    //边界条件
    if(root==nullptr)
        return ;

    realSum+=root->value;  //计算当前的和
    path.push_back(root->value);   //把当前节点（值）添加到路径中
    
    //要是是叶节点，并且路径上面节点的和等于期望的值，那么就打印路径
    bool isLeaf=(root->lchild==nullptr)&&(root->rchild==nullptr);
    if(realSum==expectedSum&&isLeaf)
    {
        std::cout<<"find a path :"<<std::endl;
        //输出
        for(auto iter=path.begin();iter!=path.end();++iter)
        {
            std::cout<<*iter<<" ";
        }
        std:cout<<std::endl;
    }
    
    //要是不是叶节点，就遍历它的子节点
    if(root->lchild!=nullptr)
        findPath(root->lchild,expectedSum,path,realSum);
        
    if(root->rchild!=nullptr)
        findPath(root->rchild,expectedSum,path,realSum);
    
    //回到父节点之前，路经上删除当前节点
    path.pop_back();
    
}
```

# 二.二叉排序树
## Ⅰ.概念和结构
二叉排序树或者叫做二叉搜索树(BST)的定义为:
>(1) 若他的左子树不为空,则左子树上所有关键字的值都小于根关键字的值

>(2) 若他的右子树不为空,则左子树上所有关键字的值都大于根关键字的值

>(3) 左右子树各又是一棵二叉搜索树.

根据定义可以知道,要是按照**中序遍历**来遍历二叉排序树的话,会发现,得到的序列就是一个有序的序列.
这也就是一个递增有序的序列.它的本质其实也就是**二分查找**.

二叉排序树的结构可以是如下所示
```c++
struct BSTNode
{
    int key;
    BSTNode* left_child;
    BSTNode* right_child;
}
```

## Ⅱ.二叉排序树基本算法
### 1.查找关键字算法

### 2.插入关键字算法

### 3.创建二叉排序树算法


Ⅲ.

# 三.平衡二叉树
