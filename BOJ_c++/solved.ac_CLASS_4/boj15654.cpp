#include<iostream>
#include<algorithm>
#include<vector>
#include"solutions.h"

using namespace std;

vector<int> target;
vector<vector<int>> q;

void show_vector(vector<int> vec) {
	for (int num : vec) {
		cout << num << ' ';
	}
	cout << '\n';
}

void listing(int N, int M, vector<int> visited, vector<int> seq) {
	vector<int> tmp = seq;
	vector<int> check = visited;
	int count = tmp.size();

	if (count == M) {
		q.push_back(tmp);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (find(check.begin(), check.end(), i) != check.end()) continue;

		tmp.push_back(target[i]);
		visited.push_back(i);
		count += 1;
		listing(N, M, visited, tmp);
		tmp.pop_back();
		visited.pop_back();
	}
}

void boj15654() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		target.push_back(tmp);
	}

	sort(target.begin(), target.end());

	// -1자리에 NULL 사용하면 NULL == 0인지 처음 조합을 다 건너뜀
	listing(N, M, {}, {});

	for (vector<int> each : q) {
		for (int num : each) {
			cout << num << ' ';
		}
		cout << '\n';
	}
}