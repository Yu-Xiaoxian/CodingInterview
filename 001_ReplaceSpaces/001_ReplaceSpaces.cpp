/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/

#include <iostream>

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (length == 0)
			return;

		char *p1 = str;
		char *p2 = p1;
		int numSpaces = 0;

		while (*p1 != '\0' && p1 - str < length) {
			if (*p1 == ' ') numSpaces++;
			p1++;
		}
		p2 = p1 + 2 * numSpaces;

		while (p1 != p2) {
			if (*p1 == ' ') {
				*p2-- = '0';
				*p2-- = '2';
				*p2-- = '%';
				p1--;
			}
			else {
				*p2-- = *p1--;
			}
		}

	}
};

int main()
{
	Solution s;
	char st[30] = " We are Happy";
	s.replaceSpace(st, 12);
	char *p = st;
	while (*p != '\0' && p - st < 20) {
		std::cout << *p;
		p++;
	}
}