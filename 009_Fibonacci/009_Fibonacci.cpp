/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/

//¼ôÉþ×Ó£ºµÝ¹éÓëµü´ú
#include <iostream>

using namespace std;
class Solution {
public:
	int Fibonacci_Solution1(int n) {
		if (n == 0)
			return 1;
		if (n == 1)
			return 1;

		return Fibonacci_Solution1(n - 1) + Fibonacci_Solution1(n-2);
	}

	int Fibonacci_Solution2(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		if (n == 2)
			return 1;
		int f_a = 1;
		int f_b = 1;
		int f_c = 0;
		for (int i = 2; i < n; i++) {
			f_c = f_a + f_b;
			f_a = f_b;
			f_b = f_c;
		}
		return f_c;
	}

	int Fibonacci_Solution3(int n) {
		return 0;
	}
};

// ====================²âÊÔ´úÂë====================
void Test(int n, int expected)
{
	Solution s;
	if (s.Fibonacci_Solution1(n) == expected)
		printf("Test for %d in solution1 passed.\n", n);
	else
		printf("Test for %d in solution1 failed.\n", n);

	if (s.Fibonacci_Solution2(n) == expected)
		printf("Test for %d in solution2 passed.\n", n);
	else
		printf("Test for %d in solution2 failed.\n", n);

	if (s.Fibonacci_Solution3(n) == expected)
		printf("Test for %d in solution3 passed.\n", n);
	else
		printf("Test for %d in solution3 failed.\n", n);
}

int main(int argc, char* argv[])
{
	Test(0, 0);
	Test(1, 1);
	Test(2, 1);
	Test(3, 2);
	Test(4, 3);
	Test(5, 5);
	Test(6, 8);
	Test(7, 13);
	Test(8, 21);
	Test(9, 34);
	Test(10, 55);

	Test(40, 102334155);

	return 0;
}
