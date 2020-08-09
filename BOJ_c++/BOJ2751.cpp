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
		cout << list[i] << '\n'; // '\n' 개행과 endl 개행의 차이 기억!
								 // endl 개행은 buffer flush까지 병행되어 훨씬 느리다.
								 // 실제로 '\n' 개행 사용시 시간 초과 문제가 발생하지 않았음.
	}
}