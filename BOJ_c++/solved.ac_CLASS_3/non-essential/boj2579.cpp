#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include"solutions.h"

using namespace std;

void boj2579() {
	int N; cin >> N;
	int answer = 0;
	vector<int> stairs;
	vector<pair<int, int>> seq;

	for (int i = 0; i < N; i++) {
		int score; cin >> score;
		stairs.push_back(score);
	}

	seq.push_back({ stairs[0], 0 });
	seq.push_back({ stairs[1], stairs[0] + stairs[1] });

	for (int i = 2; i < N; i++) {
		int first = max(seq[i - 2].first, seq[i - 2].second) + stairs[i];
		int second = seq[i - 1].first + stairs[i];
		seq.push_back({ first, second });
	}

	cout << max(seq.back().first, seq.back().second) << '\n';
}