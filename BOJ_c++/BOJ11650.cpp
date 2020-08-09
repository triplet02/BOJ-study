#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<string>
#include"solutions.h"

using namespace std;

void boj11650() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num; cin >> num;

	vector<pair<signed int, signed int>> coords(num);

	for (int i = 0; i < num; i++) {
		cin >> coords[i].first >> coords[i].second;
	}

	sort(coords.begin(), coords.end());

	for (int i = 0; i < num; i++) {
		cout << coords[i].first << ' ' << coords[i].second << '\n';
	}
}