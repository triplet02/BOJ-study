#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include"solutions.h"

using namespace std;

void boj18870() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	vector<int> target;
	vector<int> residual;

	while(N--) {
		int tmp;
		cin >> tmp;
		target.push_back(tmp);
		residual.push_back(tmp);
	}

	sort(target.begin(), target.end());
	target.erase(unique(target.begin(), target.end()), target.end());

	for (int a : residual) {
		cout << lower_bound(target.begin(), target.end(), a) - target.begin() << ' ';
	}
	cout << '\n';

	//좌표 압축
	/*
	int* target = (int*)malloc(sizeof(int)*N);
	vector<int> container;
	map<int, int> dict;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		target[i] = tmp;
		container.push_back(tmp);
	}

	sort(container.begin(), container.end());
	container.erase(unique(container.begin(), container.end()), container.end());

	for (int i = 0; i < container.size(); i++) {
		dict[container[i]] = i;
	}

	for (int i = 0; i < N; i++) {
		cout << dict[target[i]] << ' ';
	}
	cout << '\n';
	*/


	//시간초과 풀이
	/*
	int* target = (int*)malloc(sizeof(int)*N);
	int* answer = (int*)malloc(sizeof(int)*N);
	fill_n(answer, N, 0);

	for (int i = 0; i < N; i++) {
		cin >> target[i];
	}

	for (int i = 0; i < N; i++) {
		int current = target[i];
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (current > target[j]) {
				answer[i] += 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << answer[i] << ' ';
	}
	cout << '\n';
	*/
}