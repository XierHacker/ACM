//
// Created by xh on 2019/10/2.
//

#include "binary_tree.h"

#include <iostream>
#include <queue>
#include <algorithm>

//创建一个二叉树例子,返回根节点地址
BTNode *CreateExample() {
    BTNode *p1, *p2, *p3, *p4, *p5;
    //分配空间并且返回地址
    p1 = new BTNode;
    p2 = new BTNode;
    p3 = new BTNode;
    p4 = new BTNode;
    p5 = new BTNode;

    //写入结点内容
    p1->value = 1;
    p2->value = 2;
    p3->value = 3;
    p4->value = 4;
    p5->value = 5;

    p1->lchild = p2;
    p1->rchild = p3;

    p2->lchild = p4;
    p2->rchild = nullptr;

    p3->lchild = p5;
    p3->rchild = nullptr;

    p4->lchild = nullptr;
    p4->rchild = nullptr;

    p5->lchild = nullptr;
    p5->rchild = nullptr;

    return p1;
}

//先序遍历二叉树
void PreOrderTraversal(BTNode *root) {
    if (root == nullptr) { return; }       //地柜结束条件
    std::cout << root->value << " ";        //访问根节点
    PreOrderTraversal(root->lchild);    //先序遍历左子树
    PreOrderTraversal(root->rchild);    //先序遍历右子树
}

//中序遍历二叉树,递归版本和非递归版本
void InOrderTraversal(BTNode *root) {
    if (root == nullptr) { return; }
    InOrderTraversal(root->lchild);     //中序遍历左子树
    std::cout << root->value << " ";        //访问根节点
    InOrderTraversal(root->rchild);     //中序遍历右子树
}

void InOrderTraversal2(BTNode *root) {


}

//后序遍历二叉树
void PostOrderTraversal(BTNode *root) {
    if (root == nullptr) { return; }
    PostOrderTraversal(root->lchild);     //中序遍历左子树
    PostOrderTraversal(root->rchild);     //中序遍历右子树
    std::cout << root->value << " ";        //访问根节点
}

//层次遍历二叉树
void LevelTraversal(BTNode *root) {
    if (root == nullptr) { return; }
    std::queue<BTNode *> node_queue;
    node_queue.push(root);
    while (!node_queue.empty()) {
        BTNode *front_node = node_queue.front();      //取出队首
        std::cout << front_node->value << " ";          //访问
        if (front_node->lchild != nullptr) { node_queue.push(front_node->lchild); }
        if (front_node->rchild != nullptr) { node_queue.push(front_node->rchild); }
        node_queue.pop();                           //弹出队首
    }
}


//计算叶子节点数目,先序遍历
void CountLeaf(BTNode* root,int& num){
    if(root== nullptr) {return ;}
    if((root->lchild== nullptr)&&(root->rchild== nullptr)) {num+=1;}
    CountLeaf(root->lchild,num);
    CountLeaf(root->rchild,num);
}

//计算树的深度
int CountTreeDepth(BTNode* root){
    if(root== nullptr)  {return 0;}
    int LD=CountTreeDepth(root->lchild);
    int RD=CountTreeDepth(root->rchild);
    return std::max(LD,RD)+1;
}


//找树上面和为某个值的所有路径,先序遍历
void FindPathEqualToSum(BTNode* root,std::vector<int> path,int expected_sum,int current_sum){
    if(root== nullptr)  {return ;}
    path.push_back(root->value);
    current_sum+=root->value;
    //要是叶子节点同时和为expected_sum,就输出
    if((root->lchild== nullptr&&root->rchild== nullptr)&&(current_sum==expected_sum))
    {
        for(int i=0;i<path.size();i++)
        {
            std::cout<<path[i]<<" ";
        }
        std::cout<<std::endl;
    }

    //要是不是叶子节点,就遍历相应的子节点
    if(root->lchild!= nullptr)  {FindPathEqualToSum(root->lchild,path,expected_sum,current_sum);}
    if(root->rchild!= nullptr)  {FindPathEqualToSum(root->rchild,path,expected_sum,current_sum);}

    //回到父节点之前，路经上删除当前节点
    path.pop_back();
}

//输出指定节点到另外一个节点的路径,先序遍历
void FindPathBetweenNodes(BTNode* node1,BTNode* node2,std::vector<int> path){
    if((node1== nullptr)||(node2== nullptr))    {return ;}
    path.push_back(node1->value);
    //两个节点相遇
    if(node1==node2)
    {
        for(int i=0;i<path.size();i++)
        {
            std::cout<<path[i]<<" ";
        }
        std::cout<<std::endl;
    }

    //往下继续遍历
    if(node1->lchild!= nullptr) {FindPathBetweenNodes(node1->lchild,node2,path);}   //左子树
    if(node1->rchild!= nullptr) {FindPathBetweenNodes(node1->rchild,node2,path);}   //右子树

    //回到父节点之前，路经上删除当前节点
    path.pop_back();
}