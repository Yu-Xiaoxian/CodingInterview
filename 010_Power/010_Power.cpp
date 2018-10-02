/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/

//数值的整数次方

#include <iostream>
//#include <cmath>

using namespace std;

class Solution {
public:
	bool g_InvalidInput = false;

	double Power(double base, int exponent) {
		if (exponent == 0)
			return 1.0;

		if (equal(base, 0.0) && exponent < 0) {
			g_InvalidInput = true;
			return 0.0;
		}

		unsigned int absExponent = (unsigned int)exponent;
		if (exponent < 0)
			absExponent = (unsigned int)(-exponent);

		double result = PowerUnsignedExponent(base, absExponent);
		
		if (exponent > 0)
			return result;
		else
			return 1.0 / result;
	}

	double PowerUnsignedExponent(double base, unsigned int exponent) {
		double result = 1.0;
		double exp = base;
		
		while (exponent != 0) {
			if ((exponent & 0x01) == 1)
				result *= exp;
			exp *= exp;
			exponent = exponent >> 1;
		}

		return result;
	}

	bool equal(double num1, double num2)
	{
		if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
			return true;
		else
			return false;
	}
};

bool equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

// ====================测试代码====================
void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
	Solution s;
	double result = s.Power(base, exponent);
	if (equal(result, expectedResult) && s.g_InvalidInput == expectedFlag)
		std::cout << testName << " passed" << std::endl;
	else
		std::cout << testName << " FAILED" << std::endl;
}

int main(int argc, char* argv[])
{
	// 底数、指数都为正数
	Test("Test1", 2, 3, 8, false);

	// 底数为负数、指数为正数
	Test("Test2", -2, 3, -8, false);

	// 指数为负数
	Test("Test3", 2, -3, 0.125, false);

	// 指数为0
	Test("Test4", 2, 0, 1, false);

	// 底数、指数都为0
	Test("Test5", 0, 0, 1, false);

	// 底数为0、指数为正数
	Test("Test6", 0, 4, 0, false);

	// 底数为0、指数为负数
	Test("Test7", 0, -4, 0, true);

	return 0;
}