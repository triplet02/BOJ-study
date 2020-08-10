#include<iostream>
#include<algorithm>
#include"solutions.h"

using namespace std;

int process(int N) {
	switch(N){
	case 1:
		return 1;
	case 2:
		return 2;
	case 3:
		return 4;
	default:
		return process(N - 1) + process(N - 2) + process(N - 3);
	}
}

void boj9095() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	int answer;
	while (T--) {
		int N; cin >> N;

		answer = process(N);
		cout << answer << '\n';
	}
}