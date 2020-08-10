#include<iostream>
#include<algorithm>
#include<vector>
#include"solutions.h"

using namespace std;

int white = 0;
int blue = 0;

void process(vector<int>* paper, int size, int y_bias, int x_bias) {
	int check = paper[y_bias][x_bias];

	if (paper->size() == 1) {
		if (check == 1) blue++;
		else white++;
		return;
	}

	bool all_same = true;

	for (int i = y_bias; i < y_bias+size; i++) {
		for (int j = x_bias; j < x_bias+size; j++) {
			if (check != paper[i][j]) {
				all_same = false;
				break;
			}
		}
		if (!all_same) break;
	}

	if (all_same) {
		if (check == 1) blue++;
		else white++;
		return;
	}

	int adjust = size / 2; int loop = 4;
	int x_turn[4] = { 0,1,0,1 };
	int y_turn[4] = { 0,0,1,1 };
	int x_adjust, y_adjust;

	while (loop--) {
		x_adjust = adjust * x_turn[loop];
		y_adjust = adjust * y_turn[loop];

		process(paper, adjust, y_bias + y_adjust, x_bias + x_adjust);
	}
}

void boj2630() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	vector<int>* paper = new vector<int>[N];
	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			paper[i].push_back(tmp);
		}
	}
	process(paper, paper->size(), 0, 0);

	cout << white << '\n' << blue << '\n';

}