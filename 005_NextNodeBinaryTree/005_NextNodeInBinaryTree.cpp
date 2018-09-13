/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/

//��֪����һ���ڵ㣬�����������һ�������ʵĽڵ�

/*
˼·һ��
��������У������ʽڵ��������һ�����������ˡ�������ҽڵ㣬��ô��һ���ڵ�Ҳ���ҽڵ����һ���ڵ㡣
������ҽڵ㣬Ҫ�����������������Ǹ��ڵ���ҽڵ㣬��ô��һ����Ҫ���ϱ�����ֱ����ǰ�ڵ����丸�ڵ�����ӽڵ㣻
������Ǹ��ڵ����ڵ㣬��ô��һ���Ǹ��ڵ㡣

˼·��������

*/

#include<iostream>

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}

	void Connect(TreeLinkNode* pleft, TreeLinkNode* pright) {
		left = pleft;
		right = pright;
		if(pleft!=nullptr)
			pleft->next = this;
		if(pright!=nullptr)
			pright->next = this;
	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode==nullptr);
		TreeLinkNode *next;
		next = pNode;
		if (pNode->right != nullptr) {
			next = pNode->right;
			while (next->left != nullptr) {
				next = next->left;
			}
		}
		else{
			while (next->next != nullptr) {
				if (next->next->left == next) {
					break;
				}
				else {
					next = next->next;
				}
			}
			next = next->next;
		}

		return next;
	}
};

void Test(const char* textName, TreeLinkNode* pNode, int expected) {
	Solution s;
	TreeLinkNode * p_result = s.GetNext(pNode);
	int result;
	if (p_result == nullptr) {
		result = -1;
	}
	else
	{
		result = p_result->val;
	}
	if (result == expected)
		std::cout << textName << " PASSED!" << std::endl;
	else
		std::cout << textName << " has FAILED! Your Result is: " << result << " Expected: " << expected << std::endl;
}

void Test1() {
	TreeLinkNode root(0);
	TreeLinkNode Node1(1);
	TreeLinkNode Node2(2);
	TreeLinkNode Node3(3);
	TreeLinkNode Node4(4);
	TreeLinkNode Node5(5);

	root.Connect(&Node1, &Node2);
	Node1.Connect(&Node3, &Node4);
	Node2.Connect(&Node5, nullptr);

	Test("Test1", &Node5, 2);
}

void Test2() {
	TreeLinkNode root(0);
	TreeLinkNode Node1(1);
	TreeLinkNode Node2(2);
	TreeLinkNode Node3(3);
	TreeLinkNode Node4(4);
	TreeLinkNode Node5(5);

	root.Connect(&Node1, nullptr);
	Node1.Connect(&Node2, nullptr);
	Node2.Connect(&Node3, nullptr);
	Node3.Connect(&Node4, nullptr);
	Node4.Connect(&Node5, nullptr);

	Test("Test2", &root, -1);
}

void Test3() {
	TreeLinkNode root(0);
	TreeLinkNode Node1(1);
	TreeLinkNode Node2(2);
	TreeLinkNode Node3(3);
	TreeLinkNode Node4(4);
	TreeLinkNode Node5(5);

	root.Connect(&Node1, &Node2);
	Node1.Connect(&Node3, &Node4);
	Node2.Connect(nullptr, &Node5);

	Test("Test3", &Node5, -1);
}

int main() {
	Test1();
	Test2();
	Test3();

	return 0;
}