# Tree Depth  求树的深度

## Backgroud 应用背景
给定一个树的前序遍历和中序遍历，求出树的结构。假设树中没有重复的元素。

## 解题思路
### 第一思路：递归
将求一个树深度的问题，划分为求其左右两个子树的深度。

### 改正思路：迭代
树的迭代访问，通常使用栈保存路径，中序遍历过程中，在访问右节点时，会将父节点从栈中取出，导致计算出的栈深不正确。因此需要使用后序遍历，时刻保证栈中拥有整个路径，栈的大小才能代表数的深度。

[返回](./)