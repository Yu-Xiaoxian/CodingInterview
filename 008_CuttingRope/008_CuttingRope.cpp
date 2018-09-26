/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/

//剪绳子：动态规划
#include <iostream>

class Solution {
public:
	int maxProductAfterCutting_solution1(int len) {
		if (len < 2)
			return 0;
		if (len == 2)
			return 1;
		if (len == 3)
			return 2;

		int* products = new int[len+1];
		products[0] = 0;
		products[1] = 1;
		products[2] = 2;
		products[3] = 3;

		int max = 0;

		for (int i = 4; i < len+1; i++) {
			max = 0;
			for (int j = 1; j < i/2+1; j++) {
				int product = products[i - j] * products[j];
				if (max < product)
					max = product;
				products[i] = max;
			}
		}

		max = products[len];
		delete[] products;

		return max;
	}

	int maxProductAfterCutting_solution2(int len) {
		if (len < 2)
			return 0;
		if (len == 2)
			return 1;
		if (len == 3)
			return 2;

		int max = 0;

		return max;
	}
};

// ====================测试代码====================
void test(const char* testName, int length, int expected)
{
	Solution s;
	int result1 = s.maxProductAfterCutting_solution1(length);
	if (result1 == expected)
		std::cout << "Solution1 for " << testName << " passed." << std::endl;
	else
		std::cout << "Solution1 for " << testName << " FAILED." << std::endl;

	int result2 = s.maxProductAfterCutting_solution2(length);
	if (result2 == expected)
		std::cout << "Solution2 for " << testName << " passed." << std::endl;
	else
		std::cout << "Solution2 for " << testName << " FAILED." << std::endl;
}

void test1()
{
	int length = 1;
	int expected = 0;
	test("test1", length, expected);
}

void test2()
{
	int length = 2;
	int expected = 1;
	test("test2", length, expected);
}

void test3()
{
	int length = 3;
	int expected = 2;
	test("test3", length, expected);
}

void test4()
{
	int length = 4;
	int expected = 4;
	test("test4", length, expected);
}

void test5()
{
	int length = 5;
	int expected = 6;
	test("test5", length, expected);
}

void test6()
{
	int length = 6;
	int expected = 9;
	test("test6", length, expected);
}

void test7()
{
	int length = 7;
	int expected = 12;
	test("test7", length, expected);
}

void test8()
{
	int length = 8;
	int expected = 18;
	test("test8", length, expected);
}

void test9()
{
	int length = 9;
	int expected = 27;
	test("test9", length, expected);
}

void test10()
{
	int length = 10;
	int expected = 36;
	test("test10", length, expected);
}

void test11()
{
	int length = 50;
	int expected = 86093442;
	test("test11", length, expected);
}

int main(int agrc, char* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	test11();

	return 0;
}