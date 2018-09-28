/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/

//×Ö·û´®µÄÆ¥Åä

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
	vector<int> build_next(string str) {
		int m = str.length(), j = 0;
		vector<int> next;
		next.clear();
		int t = -1;
		for (int k = 0; k < m; k++)
			next.push_back(t);

		while (j < m-1) {
			if (t < 0 || str[j] == str[t]) {
				j++;
				t++;
				next[j] = t;
			}
			else {
				t = next[t];
			}
		}
		return next;
	}

public:
	int strStr_KMP(string haystack, string needle) {
		int m = needle.length();
		int n = haystack.length();
		if (n == 0 && m == 0)
			return 0;
		if (n < m)
			return -1;
		int i = 0;
		int j = 0;

		vector<int> next = build_next(needle);

		while (j < m && i < n) {
			if (0 > j || haystack[i] == needle[j]) {
				i++;
				j++;
			}
			else {
				j = next[j];
			}
		}
		if (i - j < n-m+1)
			return i - j;
		else
			return -1;
	}

	int strStr_BC(string haystack, string needle) {
		return 0;
	}

	int strStr_BM(string haystack, string needle) {
		return 0;
	}
};

void Test(const char* textName, string haystack, string needle, int expected) {
	Solution s;
	int result_KMP = s.strStr_KMP(haystack, needle);
	int result_BC = s.strStr_BC(haystack, needle);
	int result_BM = s.strStr_BM(haystack, needle);

	if (result_KMP == expected)
		cout << "KMP for " << textName << " has PASSED!" << endl;
	else
		cout << "KMP for " << textName << " has FAILED! Your result is: " << result_KMP << ". Expected: " << expected << endl;
}

void Test1() {
	string haystack = "Hello";
	string needle = "ll";

	Test("Test1", haystack, needle, 2);
}

void Test2() {
	string haystack = "Hello";
	string needle = "a";

	Test("Test2", haystack, needle, -1);
}

void Test3() {
	string haystack = "Hello";
	string needle = "Hello";

	Test("Test3", haystack, needle, 0);
}

void Test4() {
	string haystack = "Hello";
	string needle = "";

	Test("Test4", haystack, needle, 0);
}

void Test5() {
	string haystack = "mississippi";
	string needle = "issipi";

	Test("Test5", haystack, needle, -1);
}

int main() {
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	return 0;
}