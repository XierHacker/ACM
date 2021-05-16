## 一.矩阵和数组相关
### leetcode 54. 螺旋矩阵

```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int top=0;
        int bottom=matrix.size()-1;
        int left=0;
        int right=matrix[0].size()-1;
        
        while(true){
            //向右走
            for(int i=left;i<=right;i++){
                result.push_back(matrix[top][i]);
            }
            ++top; //更新top范围
            if(top>bottom){break;}

            //向下走
            for(int i=top;i<=bottom;i++){
                result.push_back(matrix[i][right]);
            }
            --right; //更新right范围
            if(right<left){break;}

            //向左走
            for(int i=right;i>=left;i--){
                result.push_back(matrix[bottom][i]);
            }
            --bottom; //更新bottom范围
            if(top>bottom){break;}

            //向上走
            for(int i=bottom;i>=top;i--){
                result.push_back(matrix[i][left]);
            }
            ++left; //更新bottom范围
            if(right<left){break;}
        }

        return result;
    
    }
};
```
就是先把四个方向的边界都找出来,然后在一个循环里面把四个方向都走一遍.同时更新边界.


## 二.数据结构相关
