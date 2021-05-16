## 一.概念
一般来说,我们很多时候需要记录一些数据的内容或者索引来进行加速,那么,我们可以用hash的方法来加速.而在C++中,其实就是`unordered_map`;



# leetcode高频题目
### 169. 多数元素

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority=0;
        int count=0;
        unordered_map<int,int> record_map;
        for(int i=0;i<nums.size();i++){
            record_map[nums[i]]+=1;
            if(record_map[nums[i]]>=count){
                count=record_map[nums[i]];
                majority=nums[i];
            }
        }
        return majority;
    }
};
```
题解:这里我构建了一个map用来记录数字和他出现的次数.所以边写入边比较就行了.加快了速度.

