#include<iostream>
#include<algorithm>
#include<vector>
#include"solutions.h"

#pragma warning(disable : 4996)

using namespace std;

void boj11866() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; scanf("%d", &N);
	int K; scanf("%d", &K); getchar();

	int del = 0;

	vector<int> list(N);
	vector<int> answer;

	for (int i = 0; i < N; i++) {
		list[i] = i+1;
	}

	while (list.size()) {
		del += K-1;
		del %= list.size();

		answer.push_back(list[del]);
		list.erase(list.begin()+del);
	}


	printf("<");
	for (int i = 0; i < N; i++ ) {
		printf("%d", answer[i]);
		if (i != N - 1) printf(", ");
	}
	printf(">");

}