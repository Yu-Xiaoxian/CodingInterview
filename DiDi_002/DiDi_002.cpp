/*******************************************************************
Copyright(c) 2018, Yu Xiaoxian
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/Yu-Xiaoxian/CodingInterview/blob/master/LICENSE.txt)
*******************************************************************/


//��ͨ�켣����

/*

Ϊ�˷�����·��ͨ״��������Ҫ��˾������ʻ�켣��������
����˾������ʻ�켣��һ���߶Σ����������ʻ�켣�ཻ�����������켣����ͬһ������
����ʱ������ӣ��켣�����᲻�����ӡ�������n�������T��ͷ�������ʾ������˾������ʻ�켣��
��Q��ͷ�������ʾ��ѯ��ǰ״̬��������ʻ�켣���������������������ʻ�켣��
��һ����t����ʾ������������ݡ�

���룻

ÿ�����ݵĵ�һ����n����ʾ���������������n�У�

��T��ͷ�ı�ʾ������˾������ʻ�켣��T�������4�����֣��ֱ��������x1, y1���յ��x2, y2��

��Q��ͷ�ı�ʾ��ѯ������ʻ�켣����������ǰ������������ʻ�켣��Q��������ֱ�ʾҪ��ѯ�Ĺ켣��id��

�켣��id��1��ʼ�����Ź켣���ӡ�

n <= 1000��

�������ӣ�T 0 0 10 0 ��ʾ�켣�����(0, 0)���յ���(10, 0)���켣id��1��T 1 - 1 1 1 ��ʾ�켣�����(1, -1)���յ���(1, 1)���켣id��5��

Q 4 ��ʾ��ѯ��ǰ״̬��idΪ4�Ĺ켣������������Ĺ켣������

��Ŀ��֤�������ݺϷ��������ѯ��δ���ֵĹ켣�����磬��ǰ�ܹ�������10���켣����ѯ����Q 11���������

�����
�����ѯ�Ľ����ÿ��һ���������ͬ��Ĳ�������֮����һ�����зָ���


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