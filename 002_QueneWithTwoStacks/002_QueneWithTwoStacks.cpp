/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/

#include <iostream>

template <class T>
class stack {
public:
	void push(T);
	T pop();
	T top();
	int size();
private:
	T *s;
};

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.size() <= 0) {
			while (stack1.size() > 0) {
				int data = stack1.top();
				stack1.pop();
				stack2.push(data);
			}
		}
		
		int data = stack2.top();
		stack2.pop();
		return data;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};