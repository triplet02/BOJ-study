#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include"solutions.h"

using namespace std;

vector<int> target;
vector<vector<int>> q;

void listing(int N, int M, int start, int selected, vector<int> seq) {
	vector<int> tmp = seq;
	int count = tmp.size();

	if (count == M) {
		q.push_back(seq);
		return;
	}

	for (int i = start; i < N; i++) {
		tmp.push_back(target[i]);
		count += 1;
		listing(N, M, i + 1, count, tmp);
		tmp.pop_back();
	}
}


void boj15650() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;

	for (int i = 1; i < N + 1; i++) {
		target.push_back(i);
	}

	listing(N, M, 0, 0, {});

	for (vector<int> each: q) {
		for (int num : each) {
			cout << num << ' ';
		}
		cout << '\n';
	}
}