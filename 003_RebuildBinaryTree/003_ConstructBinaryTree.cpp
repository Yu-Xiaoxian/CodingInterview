/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/

//已知前序遍历和中序遍历的结果，请重建二叉树

/*
思路一：
前序遍历第一个对象一定是根节点，中序遍历第一个对象一定是左叶节点。
1. 首先生成一个节点，根据前序遍历依次将节点加到二叉树左侧，直到等于中序遍历的值；
维护一个curr指针，指向当前节点。
2. 判断中序遍历的值是否等于当前节点的父节点，如果是，将curr指针移到其父节点，如果不是，将中序遍历的当前对象加到curr指向节点的右节点，直到curr指向根节点；
重复1,2两步

思路二：递归
中序遍历中，根节点之前都是其左子树节点的值，根节点之后都是其右子树的值。
将问题划分为两个等价的子问题，遍历中序遍历的结果，找到根节点的位置，从而划分为两个子序列。
*/

#include<iostream>
#include<vector>
#include<exception>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* ConstructBinaryTree(std::vector<int> pre, std::vector<int> vin) {
		if (pre.empty() || vin.empty())
			throw std::exception("Invalid input.");

		return ConstructCore(pre.begin(),pre.end(),vin.begin(),vin.end());
		//return ConstructTest(pre.begin(), pre.end(), vin.begin(), vin.end());
	}

	TreeNode* ConstructCore(
		std::vector<int>::iterator pre_bg, std::vector<int>::iterator pre_end,
		std::vector<int>::iterator vin_bg, std::vector<int>::iterator vin_end
	)
	{
		int rootValue = *pre_bg;
		TreeNode* root = new TreeNode(rootValue);

		if (pre_end - pre_bg == 1) {
			if (vin_end - vin_bg == 1 && *vin_bg == *(vin_end-1))
				return root;
			else
				throw std::exception("Invalid input");
		}

		std::vector<int>::iterator vin_root = vin_bg;
		std::vector<int>::iterator pre_mid;

		while (*vin_root != rootValue && vin_root < vin_end) {
			vin_root++;
		}

		if(vin_end == vin_root && *vin_root != rootValue)
			throw std::exception("Invalid input");

		pre_mid = pre_bg + (vin_root - vin_bg)+1;
		
		if(vin_bg < vin_root)
			root->left = ConstructCore(pre_bg+1, pre_mid, vin_bg, vin_root);
		if(vin_root+1 < vin_end)
			root->right = ConstructCore(pre_mid, pre_end, vin_root + 1, vin_end);

		return root;
	}

	TreeNode* ConstructTest(
		std::vector<int>::iterator pre_bg, std::vector<int>::iterator pre_end,
		std::vector<int>::iterator vin_bg, std::vector<int>::iterator vin_end
	)
	{
		int rootValue = *pre_bg;
		TreeNode* root = new TreeNode(rootValue);
		std::cout << root->val << std::endl;
		std::cout << *pre_bg << std::endl;
		pre_bg++;
		TreeNode* left = new TreeNode(*pre_bg);
		std::cout << left->val << std::endl;
		return root;
	}
};

int main() {
	std::vector<int> pre = {10, 6, 4, 8, 14, 12, 16};
	std::vector<int> vin = {4, 6, 8, 10, 12, 14, 16};

	Solution s;
	TreeNode* tree;
	try {
		tree = s.ConstructBinaryTree(pre, vin);
		std::cout << tree->val << std::endl;
	}
	catch(std::exception e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}