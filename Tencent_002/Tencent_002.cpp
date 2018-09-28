/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/

//游戏分数

/*
思路一：递归

思路二：迭代
*/

#include <iostream>
#include <math.h>

long long int min_freq(long long int x, long long int n) {
	if (x == 0)
		return 0;

	long long int freq, x_i, n_i;
	freq = 0;
	x_i = x;
	n_i = n;

	while (x_i>n_i) {
		x_i = x_i - n_i;
		n_i--;
		freq++;
	}
	return freq + 1;
}

int main() {
	long long int x, y, n, sum, sum_check, result;

	std::cin >> x >> y;

	if (x < 0 || y < 0) {
		std::cout << -1;
		return 0;
	}

	if (x == 0 && y == 0) {
		std::cout << 0;
		return 0;
	}

	sum = x + y;
	n = (sqrt(1 + 8 * sum) - 1) / 2;
	sum_check = (n*(n + 1)) / 2;

	if (sum_check != sum) {
		std::cout << -1;
		return 0;
	}
	result = min_freq(x, n);

	std::cout << result << std::endl;

	return 0;
}