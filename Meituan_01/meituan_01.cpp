/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/

//图的遍历，路径规划

/*
题目描述：
给定一张包含N个点、N-1条边的无向连通图，节点从1到N编号，每条边的长度均为1。假设你从1号节点出发并打算遍历所有节点，那么总路程至少是多少？

输入：
第一行包含一个整数N，1≤N≤105。
接下来N-1行，每行包含两个整数X和Y，表示X号节点和Y号节点之间有一条边，1≤X，Y≤N。

输出：
输出总路程的最小值。

样例输入：
4
1 2
1 3
3 4

样例输出：
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