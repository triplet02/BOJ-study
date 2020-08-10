#include<iostream>
#include<algorithm>
#include<vector>
#include"solutions.h"

using namespace std;

void boj11399() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	int* times;
	times = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++){
		cin >> times[i];
	}

	sort(times, times+N);

	int answer = 0;

	for (int i = 0; i < N; i++) {
		answer += (N - i) * times[i];
	}

	cout << answer << '\n';
}