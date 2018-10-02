# Fibonacci

斐波那契数列

## Backgroud 应用背景
斐波那契数列是意大利数学家提出的，数列的第n项等于前两项之和。这道题通常用来讲解递归法，以及在递归基础上的优化，从而衍生出迭代法。

## 解题思路
### 递归
递归函数分为两部分，第一部分是递归的退出条件，即n等于0和1时，返回1。当n大于等于2时，调用f(n-1)和f(n-2)相加得到数列的值。

```cpp
int Fabonacci(int n){
	if ( n < 0)
		return -1;
	if ( n==0 )
		return 0;
	if ( n==1 )
		return 1;
	return Fabonacci(n-1) + Fabonacci(n-2);
}
```

递归过程中，由于多次重复计算数列的其他成员，效率很低。

### 迭代
递归是自上而下的，迭代则是自下而上，从数列的第一项开始，按照数列的定义，逐次相加，最终得到数列的这一项。

```cpp
int Fabonacci(int n){
	if ( n < 0)
		return -1;
	if ( n==0 )
		return 0;
	if ( n==1 )
		return 1;

	int Fminus1 = 1;
	int Fminus2 = 0;
	int F;
	for (int i=2; i<=n; i++){
		F = Fminus1 + Fminus2;
		Fminus2 = Fminus1;	
		Fminus1 = F;
	}
	return F;
}
```

##拓展题目
变态跳台阶
铺砖块


[返回](./)