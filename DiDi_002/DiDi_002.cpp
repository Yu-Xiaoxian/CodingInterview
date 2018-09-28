/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/


//交通轨迹分析

/*

为了分析道路交通状况，现在要对司机的行驶轨迹划分区域。
假设司机的行驶轨迹是一条线段，如果两条行驶轨迹相交，则这两条轨迹属于同一个区域。
随着时间的增加，轨迹数量会不断增加。现在有n条命令，以T开头的命令表示新增的司机的行驶轨迹，
以Q开头的命令表示查询当前状态下这条行驶轨迹所属的区域包含多少条行驶轨迹。
第一行是t，表示多少组测试数据。

输入；

每组数据的第一行是n，表示多少条命令。接下来n行：

以T开头的表示新增的司机的行驶轨迹，T后面跟着4个数字，分别代表起点的x1, y1，终点的x2, y2。

以Q开头的表示查询该条行驶轨迹所属的区域当前包含多少条行驶轨迹。Q后面的数字表示要查询的轨迹的id。

轨迹的id从1开始，随着轨迹增加。

n <= 1000。

如下例子，T 0 0 10 0 表示轨迹起点是(0, 0)，终点是(10, 0)，轨迹id是1。T 1 - 1 1 1 表示轨迹起点是(1, -1)，终点是(1, 1)，轨迹id是5。

Q 4 表示查询当前状态下id为4的轨迹所在区域包含的轨迹数量。

题目保证测试数据合法，不会查询还未出现的轨迹（例如，当前总共插入了10条轨迹，查询出现Q 11的情况）。

输出：
输出查询的结果，每行一个结果。不同组的测试数据之间有一个空行分隔。


*/

#include <iostream>
#include <vector>

struct Quest
{
	int trace_index;
	int quest_index;
};

struct Trace {
	int x1, y1, x2, y2;
};


using namespace std;
int main() {
	int test_num;
	cin >> test_num;
	vector<Trace> trace;
	vector<Quest> ques;
	vector<vector<Trace>> t;
	vector<vector<Quest>> q;
	Trace temp_t;
	Quest temp_q;
	char temp_char;

	int n;
	for (int i = 0; i < test_num; i++) {
		cin >> n;
		temp_char = '\0';
		trace.clear();
		ques.clear();
		for (int k = 0; k < n; k++) {
			cin >> temp_char;
			if (temp_char == 'T') {
				cin >> temp_t.x1 >> temp_t.y1 >> temp_t.x2 >> temp_t.y2;
				trace.push_back(temp_t);
				//cout << "Trace" << trace.size() << endl;
			}
			if (temp_char == 'Q') {
				cin >> temp_q.quest_index;
				temp_q.trace_index = trace.size();
				ques.push_back(temp_q);
				//cout << "Ques" << trace.size() << ":" << temp_q.quest_index << endl;
			}
		}
		t.push_back(trace);
		q.push_back(ques);
	}

	for (int i = 0; i < t.size(); i++) {
		for (int j = 0; j < q[i].size(); j++) {
			//cout << q[i][j].quest_index;
			cout << 0 << endl;
		}
		cout << endl;
	}


	return 0;
}