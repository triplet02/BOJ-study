#include<iostream>
#include<algorithm>
#include<vector>
#include"solutions.h"

#pragma warning(disable : 4996)

using namespace std;

int answer[1000001];

int recursive_sol(int n) {
	int INF = 10000000;

	if (n == 1) return 0;
	if (n == 1 or n == 3) return 1;
	vector<int> tmp(3);
	tmp[0] = recursive_sol(n - 1);
	if (n % 2 == 0) tmp[1] = recursive_sol(n / 2);
	else tmp[1] = INF;

	if (n % 3 == 0) tmp[2] = recursive_sol(n / 3);
	else tmp[2] = INF;

	return *min_element(tmp.begin(), tmp.end()) + 1;
}

int compute(int n) {
	answer[1] = 0;
	answer[2] = 1; answer[3] = 1;

	if (n <= 3) return answer[n];
	else {
		for (int i = 4; i <= n; i++) {
			answer[i] = answer[i - 1] + 1;
			if (i % 2 == 0) answer[i] = min(answer[i], answer[i / 2] + 1);
			if (i % 3 == 0) answer[i] = min(answer[i], answer[i / 3] + 1);
		}
	}
	return answer[n];
}

void boj1463() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	
	cout << compute(N) << '\n';
}