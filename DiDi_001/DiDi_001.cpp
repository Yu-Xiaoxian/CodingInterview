/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/


//排列小球

/*
给定三种类型的小球P、Q、R，每种小球的数量分别为np、nq、nr个。
现在想将这些小球排成一条直线，但是不允许相同类型的小球相邻，问有多少种排列方法。
如若np=2，nq=1，nr=1则共有6种排列方式：PQRP，QPRP，PRQP，RPQP，PRPQ以及PQPR。 
如果无法组合出合适的结果，则输出0。
*/

#include <iostream>

using namespace std;

long long int times(int nq, int np, int nr) {
	if (nq == 0) {

	}
	return 0;
}

int main() {
	int np, nq, nr;
	long long int num;

	cin >> np, nq, nr;

	num = times(np, nq, nr);

	cout << num;

	return 0;
}