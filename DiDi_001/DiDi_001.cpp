/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/


//����С��

/*
�����������͵�С��P��Q��R��ÿ��С��������ֱ�Ϊnp��nq��nr����
�����뽫��ЩС���ų�һ��ֱ�ߣ����ǲ�������ͬ���͵�С�����ڣ����ж��������з�����
����np=2��nq=1��nr=1����6�����з�ʽ��PQRP��QPRP��PRQP��RPQP��PRPQ�Լ�PQPR�� 
����޷���ϳ����ʵĽ���������0��
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