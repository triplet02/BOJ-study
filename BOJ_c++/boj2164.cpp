#include<iostream>
#include<algorithm>
#include<deque>
#include"solutions.h"

#pragma warning(disable : 4996)

using namespace std;

void boj2164() {
	int num; scanf("%d", &num);

	deque<int> list;

	for (int i = 0; i < num; i++) {
		list.push_back(i+1);
	}

	while (list.size() != 1) {
		list.pop_front();
		list.push_back(list.front());
		list.pop_front();
	}

	printf("%d", list[0]);
}