#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include"solutions.h"

using namespace std;

void boj2751() {
	int num, n;
	vector<int> list;
	
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> n;
		list.push_back(n);
	}
	sort(list.begin(), list.end());
	for (int i = 0; i < num; i++) {
		cout << list[i] << '\n'; // '\n' ����� endl ������ ���� ���!
								 // endl ������ buffer flush���� ����Ǿ� �ξ� ������.
								 // ������ '\n' ���� ���� �ð� �ʰ� ������ �߻����� �ʾ���.
	}
}