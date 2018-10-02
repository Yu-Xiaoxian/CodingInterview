/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/

//��ֵ�������η�

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

// ====================���Դ���====================
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
	// ������ָ����Ϊ����
	Test("Test1", 2, 3, 8, false);

	// ����Ϊ������ָ��Ϊ����
	Test("Test2", -2, 3, -8, false);

	// ָ��Ϊ����
	Test("Test3", 2, -3, 0.125, false);

	// ָ��Ϊ0
	Test("Test4", 2, 0, 1, false);

	// ������ָ����Ϊ0
	Test("Test5", 0, 0, 1, false);

	// ����Ϊ0��ָ��Ϊ����
	Test("Test6", 0, 4, 0, false);

	// ����Ϊ0��ָ��Ϊ����
	Test("Test7", 0, -4, 0, true);

	return 0;
}