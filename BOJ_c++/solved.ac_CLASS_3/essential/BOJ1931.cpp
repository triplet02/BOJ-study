#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include"solutions.h"

using namespace std;

bool cmp(pair<int, int> a, pair<int,int> b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

void boj1931() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int start, end;
	int answer = 0;

	vector<pair<int, int>> list;

	// 끝나는 시간이 빠른 순으로 선택하면 최적의 답을 구할 것이 보장된다.
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		list.push_back(pair<int, int>(start, end));
	}	
	sort(list.begin(), list.end(), cmp);

	int now = 0;
	for (int i = 0; i < N; i++) {
		if (list[i].first >= now) {
			now = list[i].second;
			answer++;
		}
		else continue;
	}

	cout << answer << '\n';

}