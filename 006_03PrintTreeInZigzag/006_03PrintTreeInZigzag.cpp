/*******************************************************************
﻿Copyright(c) 2016, Harry He (何海涛)
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//从上到下打印二叉树，之字形

#include <stack>
#include <vector>
#include <iostream>

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

class Solution {
public:
	enum layer_stat { odd, even };

	std::vector<std::vector<int> > Print(TreeNode* pRoot) {
		std::vector<std::vector<int> > node_list;
		node_list.clear();
		if (pRoot == nullptr)
			return node_list;

		std::vector<int> temp_list;
		std::stack<TreeNode*> node_stack_odd;
		std::stack<TreeNode*> node_stack_even;
		temp_list.clear();

		layer_stat curr_layer = odd;

		TreeNode* curr = pRoot;
		node_stack_odd.push(curr);

		while (!node_stack_even.empty() || !node_stack_odd.empty()) {
			if (curr_layer == odd && !node_stack_odd.empty()) {
				curr = node_stack_odd.top();
				temp_list.push_back(curr->val);
				node_stack_odd.pop();
				if (curr->left != nullptr) {
					node_stack_even.push(curr->left);
				}
				if (curr->right != nullptr) {
					node_stack_even.push(curr->right);
				}
				if (node_stack_odd.empty()) {
					node_list.push_back(temp_list);
					temp_list.clear();
					curr_layer = even;
				}
			}
			if (curr_layer == even && !node_stack_even.empty()) {
				curr = node_stack_even.top();
				temp_list.push_back(curr->val);
				node_stack_even.pop();
				if (curr->right != nullptr)
					node_stack_odd.push(curr->right);
				if (curr->left != nullptr)
					node_stack_odd.push(curr->left);
				if (node_stack_even.empty()) {
					node_list.push_back(temp_list);
					temp_list.clear();
					curr_layer = odd;
				}
			}
		}

		return node_list;
	}
};

void Test(const char* testName, TreeNode* pRoot, std::vector<std::vector<int>> expected)
{
	Solution s;
	std::vector<std::vector<int>> result = s.Print(pRoot);

	if (result == expected)
		std::cout << testName << " has PASSED!" << std::endl;
	else {
		std::cout << testName << " has FAILED! Your result is:" << std::endl;
		for (std::vector<int> v : result) {
			for (int i : v)
				std::cout << i << " ";
			std::cout << std::endl;
		}
		std::cout << std::endl << "Expected:" << std::endl;
		for (std::vector<int> v : expected) {
			for (int i : v)
				std::cout << i << " ";
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
	TreeNode pNode10(10);
	TreeNode pNode6(6);
	TreeNode pNode14(14);
	TreeNode pNode4(4);
	TreeNode pNode8(8);
	TreeNode pNode12(12);
	TreeNode pNode16(16);

	pNode10.Connect(&pNode6, &pNode14);
	pNode6.Connect(&pNode4, &pNode8);
	pNode14.Connect(&pNode12, &pNode16);

	std::vector<std::vector<int>> result;
	std::vector<int> temp;
	result.clear();
	temp.clear();
	temp.push_back(10);
	result.push_back(temp);

	temp.clear();
	temp.push_back(14);
	temp.push_back(6);
	result.push_back(temp);

	temp.clear();
	temp.push_back(4);
	temp.push_back(8);
	temp.push_back(12);
	temp.push_back(16);
	result.push_back(temp);

	Test("Test1", &pNode10, result);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test2()
{
	TreeNode pNode5(5);
	TreeNode pNode4(4);
	TreeNode pNode3(3);
	TreeNode pNode2(2);
	TreeNode pNode1(1);

	pNode5.Connect(&pNode4, nullptr);
	pNode4.Connect(&pNode3, nullptr);
	pNode3.Connect(&pNode2, nullptr);
	pNode2.Connect(&pNode1, nullptr);

	std::vector<std::vector<int>> result;
	std::vector<int> temp;
	result.clear();
	temp.clear();
	temp.push_back(5);
	result.push_back(temp);

	temp.clear();
	temp.push_back(4);
	result.push_back(temp);

	temp.clear();
	temp.push_back(3);
	result.push_back(temp);

	temp.clear();
	temp.push_back(2);
	result.push_back(temp);

	temp.clear();
	temp.push_back(1);
	result.push_back(temp);

	Test("Test2", &pNode5, result);
}
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test3()
{
	TreeNode pNode5(5);
	TreeNode pNode4(4);
	TreeNode pNode3(3);
	TreeNode pNode2(2);
	TreeNode pNode1(1);

	pNode1.Connect(nullptr, &pNode2);
	pNode2.Connect(nullptr, &pNode3);
	pNode3.Connect(nullptr, &pNode4);
	pNode4.Connect(nullptr, &pNode5);

	std::vector<std::vector<int>> result;
	std::vector<int> temp;
	result.clear();
	temp.clear();
	temp.push_back(1);
	result.push_back(temp);

	temp.clear();
	temp.push_back(2);
	result.push_back(temp);

	temp.clear();
	temp.push_back(3);
	result.push_back(temp);

	temp.clear();
	temp.push_back(4);
	result.push_back(temp);

	temp.clear();
	temp.push_back(5);
	result.push_back(temp);

	Test("Test3", &pNode1, result);
}

// 树中只有1个结点
void Test4()
{
	TreeNode pNode1(1);

	std::vector<std::vector<int>> result;
	std::vector<int> temp;
	result.clear();
	temp.clear();
	temp.push_back(1);
	result.push_back(temp);

	Test("Test4", &pNode1, result);
}

// 树中没有结点
void Test5()
{
	std::vector<std::vector<int>> result;
	result.clear();
	Test("Test5", nullptr, result);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	return 0;
}