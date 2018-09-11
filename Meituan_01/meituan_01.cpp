/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/

//ͼ�ı�����·���滮

/*
��Ŀ������
����һ�Ű���N���㡢N-1���ߵ�������ͨͼ���ڵ��1��N��ţ�ÿ���ߵĳ��Ⱦ�Ϊ1���������1�Žڵ����������������нڵ㣬��ô��·�������Ƕ��٣�

���룺
��һ�а���һ������N��1��N��105��
������N-1�У�ÿ�а�����������X��Y����ʾX�Žڵ��Y�Žڵ�֮����һ���ߣ�1��X��Y��N��

�����
�����·�̵���Сֵ��

�������룺
4
1 2
1 3
3 4

���������
4

Hit: 1->2->1->3->4
*/

#include <iostream>

int main() {

	int numNode = 0;
	int dist = 0;
	std::cin >> numNode;
	int a, b;

	char *Nodes = new char[numNode][numNode];

	for (int i = 0; i < numNode - 1; i++) {
		std::cin >> a >> b;
		Nodes[a][b] = '#';
	}

	std::cout << dist << std::endl;
	return 0;
}