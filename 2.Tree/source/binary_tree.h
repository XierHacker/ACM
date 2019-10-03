//
// Created by xh on 2019/10/2.
//

#ifndef TREE_BINARY_TREE_H
#define TREE_BINARY_TREE_H

#include <vector>

struct BTNode {
    int value;
    BTNode *lchild;
    BTNode *rchild;
};

//创建一个二叉树例子,返回根节点地址
BTNode *CreateExample();

//先序遍历二叉树
void PreOrderTraversal(BTNode *root);

//中序遍历二叉树,递归版本和非递归版本
void InOrderTraversal(BTNode *root);

void InOrderTraversal2(BTNode *root);

//后序遍历二叉树
void PostOrderTraversal(BTNode *root);

//层次遍历二叉树
void LevelTraversal(BTNode *root);

//计算叶子节点数目
void CountLeaf(BTNode* root,int& num);

//计算树的深度
int CountTreeDepth(BTNode* root);


//找树上面和为某个值的所有路径
void FindPathEqualToSum(BTNode* root,std::vector<int> path,int expected_sum,int current_sum);

//输出指定节点到另外一个节点的路径
void FindPathBetweenNodes(BTNode* node1,BTNode* node2,std::vector<int> path);

//输出最大的和的路径
void FindPathWithMaxSum(BTNode* node1,BTNode* node2,std::vector<int> path,int& max_sum);


#endif //TREE_BINARY_TREE_H
