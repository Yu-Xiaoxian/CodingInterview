/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/

//��֪ǰ���������������Ľ�������ؽ�������

/*
˼·һ��
ǰ�������һ������һ���Ǹ��ڵ㣬���������һ������һ������Ҷ�ڵ㡣
1. ��������һ���ڵ㣬����ǰ��������ν��ڵ�ӵ���������ֱ࣬���������������ֵ��
ά��һ��currָ�룬ָ��ǰ�ڵ㡣
2. �ж����������ֵ�Ƿ���ڵ�ǰ�ڵ�ĸ��ڵ㣬����ǣ���currָ���Ƶ��丸�ڵ㣬������ǣ�����������ĵ�ǰ����ӵ�currָ��ڵ���ҽڵ㣬ֱ��currָ����ڵ㣻
�ظ�1,2����

˼·�����ݹ�
��������У����ڵ�֮ǰ�������������ڵ��ֵ�����ڵ�֮��������������ֵ��
�����⻮��Ϊ�����ȼ۵������⣬������������Ľ�����ҵ����ڵ��λ�ã��Ӷ�����Ϊ���������С�
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