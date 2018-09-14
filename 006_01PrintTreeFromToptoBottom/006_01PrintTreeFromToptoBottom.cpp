/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/

//从上到下打印二叉树，不分行

#include <vector>
#include <queue>
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
	std::vector<int> PrintFromTopToBottom(TreeNode* root) {
		std::vector<int> tree_list;
		tree_list.clear();
		if (root == nullptr)
			return tree_list;

		std::queue<TreeNode*> node_quene;
		TreeNode* curr = root;
		node_quene.push(curr);
		while (!node_quene.empty()) {
			curr = node_quene.front();
			node_quene.pop();
			tree_list.push_back(curr->val);
			if(curr->left!=nullptr)
				node_quene.push(curr->left);
			if (curr->right != nullptr)
				node_quene.push(curr->right);
		}

		return tree_list;
	}
};

void Test(const char* testName, TreeNode* pRoot, std::vector<int> expected)
{
	Solution s;
	std::vector<int> result = s.PrintFromTopToBottom(pRoot);

	if (result == expected)
		std::cout << testName << " has PASSED!" << std::endl;
	else {
		std::cout << testName << " has FAILED! Your result is:" << std::endl;
		for (int i : result)
			std::cout << i << " ";
		std::cout << std::endl << "Expected:" << std::endl;
		for (int i : expected)
			std::cout << i << " ";
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

	std::vector<int> result(7);
	result.clear();
	result.push_back(10);
	result.push_back(6);
	result.push_back(14);
	result.push_back(4);
	result.push_back(8);
	result.push_back(12);
	result.push_back(16);

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

	std::vector<int> result(5);
	result.clear();
	result.push_back(5);
	result.push_back(4);
	result.push_back(3);
	result.push_back(2);
	result.push_back(1);

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

	std::vector<int> result(5);
	result.clear();
	result.push_back(1);
	result.push_back(2);
	result.push_back(3);
	result.push_back(4);
	result.push_back(5);

	Test("Test3", &pNode1, result);
}

// 树中只有1个结点
void Test4()
{
	TreeNode pNode1(1);

	std::vector<int> result;
	result.clear();
	result.push_back(1);

	Test("Test4", &pNode1, result);
}

// 树中没有结点
void Test5()
{
	std::vector<int> result;
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