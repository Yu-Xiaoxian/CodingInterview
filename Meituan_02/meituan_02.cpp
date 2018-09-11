/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/

//�ȫ1��
/*
��Ŀ˵����
����һ��01�ַ����������=�ô����������1�ĳ��ȣ�������������K�λ��ᣬÿ�λ�����Խ����е�ĳ��0�ĳ�1�����������Ŀ��ܴ�

���룺
�����һ����������N,K����ʾ�ַ������Ⱥͻ������
�ڶ�������N����������ʾ���ַ�����Ԫ��
( 1 <= N <= 300000 , 0 <= K <= N )

�����
���һ�б�ʾ��

�������룺
10 2
1 0 0 1 0 1 0 1 0 1
���������
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