#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cctype> //isdigit()
#include"solutions.h"

#pragma warning(disable: 4996)

using namespace std;

void boj1620() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	map<string, int> name_first;
	map<int, string> idx_first;

	vector<string> answer(M);

	string target;

	for (int i = 0; i < N; i++) {
		cin >> target;
		name_first.insert(pair<string, int>(target, i + 1));
		idx_first.insert(pair<int, string>(i + 1, target));
	}

	for (int i = 0; i < M; i++) {
		cin >> target;
		if (isdigit(target[0])) {
			answer[i] = idx_first[stoi(target)];
		}
		else {
			answer[i] = to_string(name_first[target]); 
		}
	}

	for (int i = 0; i < M; i++) {
		cout << answer[i] << '\n';
	}
}