#include<iostream>
#include<algorithm>
#include<cmath>
#include"solutions.h"

using namespace std;

void sol(int N, int r, int c, int* answer) {
	if (N == 1) {
		*answer += r * 2 + c;
		//cout << "N : " << N << " / " << "r: " << r << " / " << "c : " << c << '\n';
		return;
	}
	
	int threshold = (int)pow(2, N - 1);
	int weight;
	bool r_over = false; bool c_over = false;
	if (r < threshold && c < threshold) {
		weight = 0;
	}
	else if (r < threshold && c >= threshold) {
		weight = 1;
		c_over = true;
	}
	else if (r >= threshold && c < threshold) {
		weight = 2;
		r_over = true;
	}
	else if (r >= threshold && c >= threshold) {
		weight = 3;
		r_over = true; c_over = true;
	}
	/*
	cout << "N : " << N << " / " << "r: " << r << " / " << "c : " << c << '\n';
	cout << "threshold : " << threshold << '\n';
	cout << "r_over : " << r_over << " / " << "c_over : " << c_over << '\n';
	cout << "Bias : " << weight * (int)pow(2, N) << '\n';
	*/
	*answer += (weight * (int)pow(pow(2, N - 1), 2));

	if (r_over) r -= (int)pow(2, N - 1);
	if (c_over) c -= (int)pow(2, N - 1);
	sol(N - 1, r, c, answer);
}

void boj1074() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, r, c; cin >> N >> r >> c;

	int answer = 0;

	sol(N, r, c, &answer);

	cout << answer << '\n';
}