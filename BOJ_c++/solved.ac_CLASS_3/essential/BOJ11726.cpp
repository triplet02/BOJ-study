#include<iostream>
#include<algorithm>
#include"solutions.h"

#pragma warning(disable:4996)

using namespace std;

int rec_sol(int N) {
	return (N == 1 || N == 2) ? N : rec_sol(N - 1) + rec_sol(N - 2);
}

int array_sol(int N) {
	int answer[1001];

	answer[0] = 1;
	answer[1] = 1;

	for (int i = 2; i < N+1; i++) {
		answer[i] = answer[i - 2] + answer[i - 1];
		answer[i] %= 10007; // (1)이걸 나눠서 저장해두면 정답인데
	}

	return answer[N];
}


void boj11726() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	//int N; cin >> N;
	int N;  scanf("%d", &N);

	//cout << (sol(N) % 10007) << '\n';
	printf("%d\n", array_sol(N)); // (1) 여기서 나누면 오답임 뭐지???
}