# Power with Integer Exponent

数值的整数次幂

## Backgroud 应用背景
实现Power函数，计算数值的整数次幂，需要考虑指数的正负，以及底数是否为零。以及计算的效率，是o(n)的复杂度还是o(log(n))的。

## 解题思路
### 正确性
为保证算法的正确性，首先要综合指数和底数进行判断，当底数为0且指数为负时，无法计算幂，因此需要识别这个错误。
此外还需要判断指数的正负，从而输出不同的结果。

### 蛮力
蛮力计算的思路是，用1.0依次与底数相乘，乘以n次，就得到了最终的结果。
```cpp
double PowerWithUnsignedExponent(double base, unsigned int exponent){
	double result = 1.0;

	for (int i = 0; i < n; i++){
		result *= base;
	}
	
	return result;
}
```

### 递归
递归是自上往下地计算，将求n次幂的问题划分为求n/2次幂，或者(n-1)/2的问题，将两者相乘，就得到了问题的解。其中需要对指数的奇偶性进行讨论，并区分情况。

```cpp
double PowerWithUnsignedExponent(double base, unsigned int exponent){
	if(exponent == 0)
		return 1.0;
	if(exponent == 1)
		return base;

	double result = PowerWithUnsignedExponent(base, exponent >> 1);
	result *= result;
	if(exponent&0x01 == 1)
		result *= base;
	
	return result;
}
```

### 迭代
迭代是自下向上进行计算，将指数按二进制分解，每次维护当前位数的幂，当前位为1时，乘以结果，当前位为0时，不乘。

```cpp
double PowerWithUnsignedExponent(double base, unsigned int exponent){
	double result = 1.0;
	double exp = base;

	while(exponent!=0){
		if(exponent&0x01 == 1)
			result *= exp;
		exp *= exp;
		exponent = exponent >> 1
	}
	
	return result;
}
```



[返回](./)