/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/

//��֪���ڵ㣬��������ĳ���

/*
˼·һ���ݹ�

˼·��������
��Ҫʹ�ú�����������ܱ�֤���֧�����нڵ㶼��ջ�ڡ�
���ʹ��ջ��Ԫ�ص���ڵ�һ���Ǳ����ʹ��ģ���ջ�ڵĵ�һ����û�з��ʹ��ģ����Ҫ��ջ��ȡԪ�أ���ȡջ�ڽڵ���ҽڵ㡣

*/

#include <iostream>
#include <stack>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
	void Connect(TreeNode* pleft, TreeNode* pright) {
		left = pleft;
		right = pright;
	}
};

struct TFNode {
	struct TreeNode* p = nullptr;
	bool isFist = true;
};

class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == nullptr) {
			return 0;
		}

		int dl = TreeDepth(pRoot->left) + 1;
		int dr = TreeDepth(pRoot->right) + 1;
		
		return dl > dr ? dl : dr;
	}

	int TreeDepth_iter(TreeNode* pRoot) {
		if (pRoot == nullptr)
			return 0;

		int depth = 0;

		std::stack<TFNode*> tree_stack;
		TFNode* temp;
		TreeNode* pt = pRoot;

		while (pt!=nullptr || !tree_stack.empty()) {
			while (pt != nullptr) {
				TFNode *curr = new TFNode;
				curr->p = pt;
				curr->isFist = true;
				tree_stack.push(curr);
				depth = depth > tree_stack.size() ? depth : tree_stack.size();
				pt = pt->left;
			}
			if (!tree_stack.empty()) {
				temp = tree_stack.top();
				if (temp->isFist) {
					temp->isFist = false;
					pt = temp->p->right;
				}
				else
				{
					tree_stack.pop();
				}
			}
		}

		return depth;
	}
};

void Test(const char* testName, TreeNode* pRoot, int expected)
{
	Solution s;
	
	int result1 = s.TreeDepth(pRoot);
	if (expected == result1)
		std::cout << testName << " of Recur PASSED!" << std::endl;
	else
		std::cout << testName << " of Recur FAILED! Your result is: " << result1 << ". Expected: " << expected << std::endl;

	int result2 = s.TreeDepth_iter(pRoot);
	if (expected == result2)
		std::cout << testName << " of Iteration PASSED!" << std::endl;
	else
		std::cout << testName << " of Iteration FAILED! Your result is: " << result2 << ". Expected: " << expected << std::endl;
}

void Test1() {
	TreeNode root(0);
	TreeNode pNode1(1);
	TreeNode pNode2(2);
	root.Connect(&pNode1, &pNode2);

	Test("Test1",&root,2);
}

void Test2() {
	TreeNode root(0);
	TreeNode pNode1(1);
	TreeNode pNode2(2);
	root.Connect(&pNode1, nullptr);
	pNode1.Connect(&pNode2, nullptr);

	Test("Test2",&root,3);
}

void Test3() {
	TreeNode root(0);
	TreeNode pNode1(1);
	TreeNode pNode2(2);
	TreeNode pNode3(3);
	TreeNode pNode4(4);
	TreeNode pNode5(5);
	TreeNode pNode6(6);
	root.Connect(&pNode1,&pNode2);
	pNode1.Connect(&pNode3,&pNode4);
	pNode2.Connect(nullptr, &pNode5);
	pNode4.Connect(&pNode6,nullptr);

	Test("Test3", &root, 4);
}

int main() {
	Test1();
	Test2();
	Test3();
	std::cout << " " << std::endl;
	return 0;
}