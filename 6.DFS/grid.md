# 矩阵,棋盘类(网格)问题

网格问题是由 `m \times n` 个小方格组成一个网格，每个小方格与其上下左右四个方格认为是相邻的，要在这样的网格上进行某种搜索。

## 一.网格DFS 的基本结构
网格结构要比二叉树结构稍微复杂一些，它其实是一种简化版的图结构。要写好网格上的 DFS 遍历，我们首先要理解二叉树上的 DFS 遍历方法，再类比写出网格结构上的 DFS 遍历。

我们写的二叉树 DFS 遍历一般是这样的：

```C++
//先序遍历二叉树
void PreOrderTraversal(BTNode* root){
    //递归结束条件
    if(root== nullptr) {
        return ;
    }       
    std::cout<<root->value<<" ";        //访问根节点
    PreOrderTraversal(root->lchild);    //先序遍历左子树
    PreOrderTraversal(root->rchild);    //先序遍历右子树
}
```
可以看到，二叉树的 DFS 有两个要素：「访问相邻结点」和「判断 base case」。

第一个要素是访问相邻结点。二叉树的相邻结点非常简单，只有左子结点和右子结点两个。二叉树本身就是一个递归定义的结构：一棵二叉树，它的左子树和右子树也是一棵二叉树。那么我们的 DFS 遍历只需要递归调用左子树和右子树即可。

第二个要素是 判断 base case。一般来说，二叉树遍历的 base case 是 root == null。这样一个条件判断其实有两个含义：一方面，这表示 root 指向的子树为空，不需要再往下遍历了。另一方面，在 root == null 的时候及时返回，可以让后面的 root.left 和 root.right 操作不会出现空指针异常。


对于网格上的 DFS，我们完全可以参考二叉树的 DFS，写出网格 DFS 的两个要素：

首先，网格结构中的格子有多少相邻结点？答案是上下左右四个。对于格子 `(r, c)` 来说（`r` 和 `c` 分别代表行坐标和列坐标），四个相邻的格子分别是 `(r-1, c)`、`(r+1, c)`、`(r, c-1)`、`(r, c+1)`。换句话说，网格结构是「四叉」的。

![](https://pic.leetcode-cn.com/63f5803e9452ccecf92fa64f54c887ed0e4e4c3434b9fb246bf2b410e4424555.jpg)

其次，网格 DFS 中的 base case 是什么？从二叉树的 base case 对应过来，应该是网格中不需要继续遍历、grid[r][c] 会出现数组下标越界异常的格子，也就是那些超出网格范围的格子。

![](https://pic.leetcode-cn.com/5a91ec351bcbe8e631e7e3e44e062794d6e53af95f6a5c778de369365b9d994e.jpg)

这一点稍微有些反直觉，坐标竟然可以临时超出网格的范围？这种方法我称为「先污染后治理」—— 甭管当前是在哪个格子，先往四个方向走一步再说，如果发现走出了网格范围再赶紧返回。这跟二叉树的遍历方法是一样的，先递归调用，发现 root == null 再返回。

这样，我们得到了网格 DFS 遍历的框架代码：

```c++

void dfs(vector<vector<int>>, int r, int c) {
    // 判断 base case
    // 如果坐标 (r, c) 超出了网格范围，直接返回
    if (!inArea(grid, r, c)) {
        return;
    }
    // 访问上、下、左、右四个相邻结点
    dfs(grid, r - 1, c);
    dfs(grid, r + 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r, c + 1);
}

// 判断坐标 (r, c) 是否在网格中
boolean inArea(vector<vector<int>> grid, int r, int c) {
    return (r>=0) && (r < grid.size()) && (c>=0) && (c < grid[0].size);
}
```








## 二.岛屿问题
岛屿问题是一类典型的网格问题。每个格子中的数字可能是 0 或者 1。我们把数字为 0 的格子看成海洋格子，数字为 1 的格子看成陆地格子，这样相邻的陆地格子就连接成一个岛屿。
![](https://pic.leetcode-cn.com/c36f9ee4aa60007f02ff4298bc355fd6160aa2b0d628c3607c9281ce864b75a2.jpg)

在这样一个设定下，就出现了各种岛屿问题的变种，包括岛屿的数量、面积、周长等。不过这些问题，基本都可以用 DFS 遍历来解决。

### 如何避免重复遍历
网格结构的 DFS 与二叉树的 DFS 最大的不同之处在于，遍历中可能遇到遍历过的结点。这是因为，网格结构本质上是一个「图」，我们可以把每个格子看成图中的结点，每个结点有向上下左右的四条边。在图中遍历时，自然可能遇到重复遍历结点。

这时候，DFS 可能会不停地「兜圈子」，永远停不下来，如下图所示：

![](https://pic.leetcode-cn.com/7fec64afe8ab72c5df17d6a41a9cc9ba3879f58beec54a8791cbf108b9fd0685.gif)

如何避免这样的重复遍历呢？答案是标记已经遍历过的格子。以岛屿问题为例，我们需要在所有值为 1 的陆地格子上做 DFS 遍历。每走过一个陆地格子，就把格子的值改为 2，这样当我们遇到 2 的时候，就知道这是遍历过的格子了。也就是说，每个格子可能取三个值：

- 0 —— 海洋格子
- 1 —— 陆地格子（未遍历过）
- 2 —— 陆地格子（已遍历过）
我们在框架代码中加入避免重复遍历的语句：

```c++

void dfs(vector<vector<int>> grid, int r, int c) {
    // 判断 base case
    // 如果坐标 (r, c) 超出了网格范围，直接返回
    if (!inArea(grid, r, c)) {
        return;
    }
    // 如果这个格子不是岛屿，直接返回
    if (grid[r][c] != 1) {
        return;
    }
    grid[r][c] = 2; // 将格子标记为「已遍历过」

    // 访问上、下、左、右四个相邻结点
    dfs(grid, r - 1, c);
    dfs(grid, r + 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r, c + 1);
}

// 判断坐标 (r, c) 是否在网格中
boolean inArea(vector<vector<int>> grid, int r, int c) {
    return (r>=0) && (r < grid.size()) && (c>=0) && (c < grid[0].size);
}
```
![](https://pic.leetcode-cn.com/20fe202fb5e5fc5048e140c29310c1bcbb17661860d2441e8a3feb1236a2e44d.gif)



### leetcode 695. 岛屿的最大面积
```c++
class Solution {
public:
    int dfs(vector<vector<int>>& grid,int row,int col){
        //终止条件
        if(!in_area(grid,row,col)){
            return 0;
        }
        if(grid[row][col]!=1){
            return 0;
        }
        grid[row][col]=2;      //表示访问过
        return 1+dfs(grid,row-1,col)+dfs(grid,row+1,col)+dfs(grid,row,col-1)+dfs(grid,row,col+1);
    }

    bool in_area(vector<vector<int>>& grid,int row,int col){
        return (row>=0)&&(row<grid.size())&&(col>=0)&&(col<grid[0].size());
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int area=dfs(grid,i,j);
                    max_area=(max_area>area?max_area:area);
                }  
            }
        }
        return max_area;
    }
};
```

题解:
遍历每一个点,每个点要是为1的话,我就以这个点为中心辐射.而在dfs函数中,把全部的面积加起来就行了.

### 200. 岛屿数量
```c++
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int row,int col){
        if(!in_area(grid,row,col)){
            return ;
        }
        if(grid[row][col]!='1'){
            return ;
        }
        grid[row][col]='2';  //遍历过
        dfs(grid,row-1,col);
        dfs(grid,row+1,col);
        dfs(grid,row,col-1);
        dfs(grid,row,col+1);
        return ;
    }

    bool in_area(vector<vector<char>>& grid,int row,int col){
        return (row>=0)&&(row<grid.size())&&(col>=0)&&(col<grid[0].size());
    }

    int numIslands(vector<vector<char>>& grid) {
        int num=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]=='1'){
                    ++num;
                    dfs(grid,i,j);
                }
            }
        }
        return num;

    }
};
```
题解:
和上面的核心思想一样,就是没dfs一次,基本上就把一个岛屿的全部面积都得到了,因此,只要数遍历多少次就行了.




## 二.棋盘问题