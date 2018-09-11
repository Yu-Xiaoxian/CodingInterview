/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/

//最长全1串
/*
题目说明：
给你一个01字符串，定义答案=该串中最长的连续1的长度，现在你有至多K次机会，每次机会可以将串中的某个0改成1，现在问最大的可能答案

输入：
输入第一行两个整数N,K，表示字符串长度和机会次数
第二行输入N个整数，表示该字符串的元素
( 1 <= N <= 300000 , 0 <= K <= N )

输出：
输出一行表示答案

样例输入：
10 2
1 0 0 1 0 1 0 1 0 1
样例输出：
5
*/

#include <iostream>


int main() {

	int lenStr = 0;
	int k = 0;
	int lenof1 = 0;
	char temp = ' ';
	std::cin >> lenStr >> k;

	char *str = new char[lenStr+1];
	char *p1 = str;
	char *p2 = str;

	int *numof1 = new int[lenStr+1];

	for (int i = 0; i < lenStr; i++) {
		while(temp != '1' && temp != '0') std::cin >> temp;
		str[i] = temp;
		temp = ' ';
	}
	str[lenStr] = '\0';

	while (p1 - str < lenStr && p2 - str < lenStr) {
		if (*p1 == '1') {
			if (*p2 == '1') {
				p2++;
			}
			else {
				lenof1 = (p2 - p1) > lenof1 ? (p2 - p1) : lenof1;
				p1 = ++p2;
			}
		}
		else {
			p2 = ++p1;
		}
	}

	delete[] str;
	delete[] numof1;
	std::cout << lenof1 << std::endl;
	return 0;
}