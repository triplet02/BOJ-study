#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include"solutions.h"

#pragma warning(disable : 4996)

using namespace std;

bool compare(const pair<int, string> a, const pair<int, string> b) {
	return a.first < b.first;
}

void boj10814() {
	int num;
	cin >> num;

	vector<pair<int, string> > user(num);
	for (int i = 0; i < num; i++) {
		cin >> user[i].first >> user[i].second;
	}

	stable_sort(user.begin(), user.end(), compare);

	for (int i = 0; i < num; i++) {
		cout << user[i].first << ' ' << user[i].second << '\n';
	}
}